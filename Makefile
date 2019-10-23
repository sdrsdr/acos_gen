default: run

PREFIX ?=
CFLAGS ?= -std=gnu11
LIBS = -lm

GCC = $(PREFIX)gcc

TARGET ?= acos_table_test

build: $(TARGET)

acos_table_test: acos_table_test.c acos_table.c
	$(GCC) $(CFLAGS)  -o $@ $^ $(LIBS)

run: $(TARGET)
	./$(TARGET)

bincode:
	rm acos_table_loop.o acos_table_loop.bin
	~/opt/gcc-arm-none-eabi/bin/arm-none-eabi-gcc -c -o acos_table_loop.o  acos_table_loop.c
	~/opt/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy  -S -O binary acos_table_loop.o acos_table_loop.bin 
	ls -l acos_table_loop.o acos_table_loop.bin
	rm acos_table_loop.o acos_table_loop.bin
