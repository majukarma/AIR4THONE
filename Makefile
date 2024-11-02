# Makefile

CC = gcc
CFLAGS = -Wall -Wextra  
LDFLAGS =
OBJFILES = main.o interpreter.o stack.o variables.o words.o common.o
TARGET = forth_interpreter

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET) $(LDFLAGS)

main.o: main.c interpreter.h
	$(CC) $(CFLAGS) -c main.c

interpreter.o: interpreter.c interpreter.h stack.h variables.h words.h
	$(CC) $(CFLAGS) -c interpreter.c

stack.o: stack.c stack.h common.h
	$(CC) $(CFLAGS) -c stack.c

variables.o: variables.c variables.h common.h
	$(CC) $(CFLAGS) -c variables.c

words.o: words.c words.h common.h
	$(CC) $(CFLAGS) -c words.c

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c

clean:
	rm -f $(OBJFILES) $(TARGET)
