#ifndef I2C_H
#define I2C_H

int func_set_opt(int fd);
int func_write_regs(int fd, unsigned char devaddr, unsigned char reg, unsigned char *buf, int data_len);
int func_read_regs(int fd, unsigned char devaddr, unsigned char reg, unsigned char *buf, int data_len);

#endif
