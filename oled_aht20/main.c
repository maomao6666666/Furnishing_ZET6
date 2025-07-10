#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include "i2c.h"

#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_DEV_OLED "/dev/i2c-4"
#define I2C_DEV_AHT  "/dev/i2c-7"
#define OLED_ADDR 0x3C
#define AHT20_ADDR 0x38

// 6x8 ASCII 字模表 (仅数字)
unsigned char font6x8[][6] = {
    {0x3E,0x51,0x49,0x45,0x3E,0x00}, // 0
    {0x00,0x42,0x7F,0x40,0x00,0x00}, // 1
    {0x42,0x61,0x51,0x49,0x46,0x00}, // 2
    {0x21,0x41,0x45,0x4B,0x31,0x00}, // 3
    {0x18,0x14,0x12,0x7F,0x10,0x00}, // 4
    {0x27,0x45,0x45,0x45,0x39,0x00}, // 5
    {0x3C,0x4A,0x49,0x49,0x30,0x00}, // 6
    {0x01,0x71,0x09,0x05,0x03,0x00}, // 7
    {0x36,0x49,0x49,0x49,0x36,0x00}, // 8
    {0x06,0x49,0x49,0x29,0x1E,0x00},  // 9
    {0x01, 0x01, 0x7F, 0x01, 0x01, 0x00}, // 10: 'T'
    {0x3C, 0x42, 0x81, 0x81, 0x42, 0x00}, // 11: 'C'
    {0x43, 0x23, 0x10, 0x08, 0x64, 0x62}, // 12: '%'
    {0x00, 0x36, 0x36, 0x00, 0x00, 0x00}, // 13: ':'
    {0x00, 0x00, 0x60, 0x60, 0x00, 0x00}, // 14: '.'
    {0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00},  // 15: 'H'
};

void oled_write_cmd(int fd, unsigned char cmd) {
    unsigned char buf[2] = {0x00, cmd};
    write(fd, buf, 2);
}

void oled_write_data(int fd, unsigned char *data, int len) {
    unsigned char *buf = malloc(len + 1);
    buf[0] = 0x40;
    memcpy(buf + 1, data, len);
    write(fd, buf, len + 1);
    free(buf);
}

void oled_init(int fd) {
    oled_write_cmd(fd, 0xAE);
    oled_write_cmd(fd, 0x20);
    oled_write_cmd(fd, 0x00);
    oled_write_cmd(fd, 0xB0);
    oled_write_cmd(fd, 0xC8);
    oled_write_cmd(fd, 0x00);
    oled_write_cmd(fd, 0x10);
    oled_write_cmd(fd, 0x40);
    oled_write_cmd(fd, 0x81);
    oled_write_cmd(fd, 0xFF);
    oled_write_cmd(fd, 0xA1);
    oled_write_cmd(fd, 0xA6);
    oled_write_cmd(fd, 0xA8);
    oled_write_cmd(fd, 0x3F);
    oled_write_cmd(fd, 0xA4);
    oled_write_cmd(fd, 0xD3);
    oled_write_cmd(fd, 0x00);
    oled_write_cmd(fd, 0xD5);
    oled_write_cmd(fd, 0xF0);
    oled_write_cmd(fd, 0xD9);
    oled_write_cmd(fd, 0x22);
    oled_write_cmd(fd, 0xDA);
    oled_write_cmd(fd, 0x12);
    oled_write_cmd(fd, 0xDB);
    oled_write_cmd(fd, 0x20);
    oled_write_cmd(fd, 0x8D);
    oled_write_cmd(fd, 0x14);
    oled_write_cmd(fd, 0xAF);
}

void oled_set_cursor(int fd, int page, int col) {
    oled_write_cmd(fd, 0xB0 + page);
    oled_write_cmd(fd, 0x00 + (col & 0x0F));
    oled_write_cmd(fd, 0x10 + ((col >> 4) & 0x0F));
}

void oled_show_char(int fd, int page, int col, char ch) {
    int index = 0;
    if (ch >= '0' && ch <= '9') {
        index = ch - '0';
    } else if (ch == 'T') {
        index = 10;
    } else if (ch == 'C') {
        index = 11;
    } else if (ch == '%') {
        index = 12;
    } else if (ch == ':') {
        index = 13;
    } else if (ch == '.') {
        index = 14;   
    } else if (ch == 'H') {
        index = 15; 
    } else {
        // 不支持的字符显示空白
        unsigned char blank[6] = {0};
        oled_set_cursor(fd, page, col);
        oled_write_data(fd, blank, 6);
        return;
    }
    oled_set_cursor(fd, page, col);
    oled_write_data(fd, font6x8[index], 6);
}


void oled_show_string(int fd, int page, int col, const char *str) {
    while (*str && col <= 122) {  // 避免超出右边界
        oled_show_char(fd, page, col, *str);
        col += 6;  // 每个字符宽6列
        str++;
    }
}

void oled_clear_page(int fd, int page) {
    oled_set_cursor(fd, page, 0);
    unsigned char blank[128];
    memset(blank, 0x00, sizeof(blank));  // 清空一整页（128列）
    oled_write_data(fd, blank, 128);
}

void oled_clear_screen(int fd) {
    unsigned char blank[128];  // OLED宽度一般128列
    memset(blank, 0x00, sizeof(blank));  // 全部置0

    for (int page = 0; page < 9; page++) {  // 一般6页
        oled_set_cursor(fd, page, 0);       // 定位到每页第0列
        oled_write_data(fd, blank, 128);    // 写入一整页空数据
    }
}


int read_aht20(int fd, float *temp, float *humi) {
    unsigned char cmd[3] = {0xAC, 0x33, 0x00};
    if (write(fd, cmd, 3) != 3) return -1;
    usleep(800000); // 800ms等待数据准备
    unsigned char data[6] = {0};
    if (read(fd, data, 6) != 6) return -2;
    if (data[0] & 0x80) return -3;

    unsigned int raw_humi = ((data[1] << 12) | (data[2] << 4) | (data[3] >> 4));
    unsigned int raw_temp = ((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5];

    *humi = (float)raw_humi * 100.0 / 1048576.0;
    *temp = (float)raw_temp * 200.0 / 1048576.0 - 50.0;
    return 0;
}

int main() {
    int fd_oled = open(I2C_DEV_OLED, O_RDWR);
    if (fd_oled < 0) {
        perror("open OLED i2c failed");
        return -1;
    }
    ioctl(fd_oled, I2C_SLAVE, OLED_ADDR);
    oled_init(fd_oled);

    int fd_aht = open(I2C_DEV_AHT, O_RDWR);
    if (fd_aht < 0) {
        perror("open AHT20 i2c failed");
        close(fd_oled);
        return -1;
        
    }
    ioctl(fd_aht, I2C_SLAVE, AHT20_ADDR);

    char buf[32];
    float temperature, humidity;
    
    

    while (1) {
        if (read_aht20(fd_aht, &temperature, &humidity) == 0) {
        
            oled_clear_screen(fd_oled);
      
            snprintf(buf, sizeof(buf), "T:%.1fC", temperature);
            oled_show_string(fd_oled, 2, 0, buf);
            snprintf(buf, sizeof(buf), "H:%.1f%%", humidity);
            oled_show_string(fd_oled, 3, 0, buf);
           
            
        } else {
            oled_show_string(fd_oled, 0, 0, "Sensor Err");
        }
        sleep(2);
    }
    close(fd_aht);
    close(fd_oled);
    return 0;
}
