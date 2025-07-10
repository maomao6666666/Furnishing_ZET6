#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include "i2c.h"

#include <linux/i2c-dev.h>
#include <linux/i2c.h>

int func_set_opt(int fd)
{
    int ret;
    ret = ioctl(fd, I2C_TIMEOUT, 2);
    if (ret == -1)
        perror("set timeout failed");

    ret = ioctl(fd, I2C_RETRIES, 1);
    if (ret == -1)
        perror("set retries failed");

    return 0;
}

int func_write_regs(int fd, unsigned char devaddr, unsigned char reg, unsigned char *buf, int data_len)
{
    unsigned char *data = malloc(data_len + 1);
    if (!data) return -1;
    data[0] = reg;
    memcpy(&data[1], buf, data_len);

    struct i2c_msg msgs[1] = {
        {
            .addr = devaddr,
            .flags = 0,
            .len = data_len + 1,
            .buf = data
        }
    };

    struct i2c_rdwr_ioctl_data ioctl_data = {
        .msgs = msgs,
        .nmsgs = 1
    };

    int ret = ioctl(fd, I2C_RDWR, &ioctl_data);
    free(data);
    if (ret < 0)
        perror("write_regs failed");
    return ret;
}

int func_read_regs(int fd, unsigned char devaddr, unsigned char reg, unsigned char *buf, int data_len)
{
    unsigned char reg_buf[1] = {reg};

    struct i2c_msg msgs[2] = {
        {
            .addr = devaddr,
            .flags = 0, // write
            .len = 1,
            .buf = reg_buf
        },
        {
            .addr = devaddr,
            .flags = I2C_M_RD,
            .len = data_len,
            .buf = buf
        }
    };

    struct i2c_rdwr_ioctl_data ioctl_data = {
        .msgs = msgs,
        .nmsgs = 2
    };

    int ret = ioctl(fd, I2C_RDWR, &ioctl_data);
    if (ret < 0)
        perror("read_regs failed");
    return ret;
}
