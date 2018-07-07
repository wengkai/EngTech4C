
PROJECT = blink

TOOLDIR = /usr/local/gcc-arm-none-eabi
TOOLPREFIX = $(TOOLDIR)/bin/arm-none-eabi
CC = $(TOOLPREFIX)-gcc
OBJCOPY = $(TOOLPREFIX)-objcopy
LIBSRC = Libraries/STM32F10x_StdPeriph_Driver/src
CMSIS = Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
COMPORT = /dev/tty.SLAB_USBtoUART

OBJS = src/main.o src/uart.o src/time.o src/a7.o src/strfmt.o src/log.o\
	src/stm32f10x_it.o \
	$(LIBSRC)/stm32f10x_gpio.o \
	$(LIBSRC)/stm32f10x_rcc.o \
	$(LIBSRC)/stm32f10x_usart.o \
	$(LIBSRC)/stm32f10x_dma.o \
	$(LIBSRC)/misc.o \
	$(CMSIS)/system_stm32f10x.o \
	$(CMSIS)/startup/startup_stm32f10x_md_vl.o
 
CFLAG = -nostartfiles -Xlinker --gc-sections -Wl,-Map,$(PROJECT).map -mcpu=cortex-m3 -mthumb
MACRO = -DSTM32F10X_LD -DUSE_STDPERIPH_DRIVER
INCLUDE = \
	-ILibraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x \
	-ILibraries/CMSIS/CM3/CoreSupport \
	-ILibraries/STM32F10x_StdPeriph_Driver/inc \
	-Isrc

all: $(PROJECT).hex

$(PROJECT).hex: $(PROJECT).elf
	@echo 'Making $@'
	$(OBJCOPY) -O ihex blink.elf $@
	@echo 'Finished building target: $@'

$(PROJECT).elf: $(OBJS)
	@echo 'Building : $@'
	$(CC) -T"stm32_flash.ld" $(INCLUDE) $(MACRO) $(CFLAG) -o $@ $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'

.c.o:
	$(CC) $(CFLAG) $(INCLUDE) $(MACRO) -c -o $@ $<

dl: $(PROJECT).hex
	stm32isp -term 9600 -verbose -bootp RTS -reset DTR $(PROJECT).hex $(COMPORT) 115200

term: $(PROJECT).hex
	stm32isp -term 9600 -termonly -verbose -bootp RTS -reset DTR $(PROJECT).hex $(COMPORT) 115200

clean:
	rm $(OBJS)
