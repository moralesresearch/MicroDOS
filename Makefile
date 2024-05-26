CXX = aarch64-elf-g++
AS = aarch64-elf-as
LD = aarch64-elf-ld
OBJCOPY = aarch64-elf-objcopy
# INCLUDE_PATH = 
CFLAGS = -Wall -O2 -ffreestanding -nostdlib -nostartfiles -fno-exceptions -fno-rtti -Iinclude

all: kernel.img

kernel.img: kernel7.elf
	$(OBJCOPY) kernel7.elf -O binary kernel.img

kernel7.elf: bootloader.o main.o uart.o timer.o gpio.o memory.o interrupts.o shell.o jvm.o framebuffer.o window.o filesystem.o process.o minimal_string.o minimal_defs.o minimal_map.o minimal_alloc.o
	$(LD) -T linker.ld -o kernel7.elf bootloader.o main.o uart.o timer.o gpio.o memory.o interrupts.o shell.o jvm.o framebuffer.o window.o filesystem.o process.o minimal_string.o minimal_defs.o minimal_map.o minimal_alloc.o

bootloader.o: boot/bootloader.S
	$(AS) boot/bootloader.S -o bootloader.o

main.o: kernel/main.cpp
	$(CXX) $(CFLAGS) -c kernel/main.cpp -o main.o

uart.o: kernel/drivers/uart.cpp
	$(CXX) $(CFLAGS) -c kernel/drivers/uart.cpp -o uart.o

timer.o: kernel/drivers/timer.cpp
	$(CXX) $(CFLAGS) -c kernel/drivers/timer.cpp -o timer.o

gpio.o: kernel/drivers/gpio.cpp
	$(CXX) $(CFLAGS) -c kernel/drivers/gpio.cpp -o gpio.o

memory.o: kernel/memory.cpp
	$(CXX) $(CFLAGS) -c kernel/memory.cpp -o memory.o

interrupts.o: kernel/interrupts.cpp
	$(CXX) $(CFLAGS) -c kernel/interrupts.cpp -o interrupts.o

shell.o: user/shell.cpp
	$(CXX) $(CFLAGS) -c user/shell.cpp -o shell.o

jvm.o: kernel/jvm.cpp
	$(CXX) $(CFLAGS) -c kernel/jvm.cpp -o jvm.o

framebuffer.o: kernel/drivers/framebuffer.cpp
	$(CXX) $(CFLAGS) -c kernel/drivers/framebuffer.cpp -o framebuffer.o

window.o: kernel/window.cpp
	$(CXX) $(CFLAGS) -c kernel/window.cpp -o window.o

filesystem.o: kernel/filesystem.cpp
	$(CXX) $(CFLAGS) -c kernel/filesystem.cpp -o filesystem.o

process.o: kernel/process.cpp
	$(CXX) $(CFLAGS) -c kernel/process.cpp -o process.o

minimal_string.o: kernel/minimal_string.cpp
	$(CXX) $(CFLAGS) -c kernel/minimal_string.cpp -o minimal_string.o

minimal_defs.o: kernel/minimal_defs.cpp
	$(CXX) $(CFLAGS) -c kernel/minimal_defs.cpp -o minimal_defs.o

minimal_map.o: kernel/minimal_map.cpp
	$(CXX) $(CFLAGS) -c kernel/minimal_map.cpp -o minimal_map.o

minimal_alloc.o: kernel/minimal_alloc.cpp
	$(CXX) $(CFLAGS) -c kernel/minimal_alloc.cpp -o minimal_alloc.o

clean:
	rm -f *.o *.elf *.img