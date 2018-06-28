CC := gcc
CFLAG := -O3 -Wall
OBJS := main.o eval.o
TARGET := eval

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $<