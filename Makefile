PATH := $(DEVKITARM)/bin:$(PATH)

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mthumb-interwork -mthumb -O2 -Wall
LDFLAGS = -mthumb-interwork -mthumb -specs=gba.specs

TARGET = geometry_dash_gba

all: $(TARGET).gba

$(TARGET).elf: main.c
	$(CC) $(CFLAGS) main.c $(LDFLAGS) -o $(TARGET).elf

$(TARGET).gba: $(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).gba

clean:
	rm -f $(TARGET).elf $(TARGET).gba
