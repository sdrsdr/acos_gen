default: run

PREFIX ?=
CFLAGS ?= -std=gnu11
LIBS = -lm

GCC = $(PREFIX)gcc

TARGET ?= acos_table_test

build: $(TARGET)

acos_table_test: acos_table_test.c acos_table_loop.c
	$(GCC) $(CFLAGS)  -o $@ $^ $(LIBS)

run: $(TARGET)
	./$(TARGET)