###############################################################################
# Makefile for the project MG
###############################################################################

## General Flags
PROJECT = MG
MCU = atmega128
TARGET = MG.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=MG.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = uart.o mpu6050dmp6.o MPU6050.o twimaster.o hmc5883l.o main.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) MG.hex MG.eep MG.lss## Compile
uart.o: ../uart/uart.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

mpu6050dmp6.o: ../mpu6050/mpu6050dmp6.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

MPU6050.o: ../mpu6050/MPU6050.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

twimaster.o: ../i2chw/twimaster.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

hmc5883l.o: ../hmc5883l/hmc5883l.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

main.o: ../main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) MG.elf dep/* MG.hex MG.eep MG.lss MG.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

