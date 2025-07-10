CROSS_COMPILE := /home/elf/work/02-0_SDK/ELF2-linux-source/prebuilts/gcc/linux-x86/aarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -O2

TARGET := aht20_oled

all: $(TARGET)

$(TARGET): main.c i2c.c i2c.h
	$(CC) $(CFLAGS) main.c i2c.c -o $(TARGET) -lm

clean:
	rm -f $(TARGET)

