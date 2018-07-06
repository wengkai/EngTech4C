CC = gcc
TARGET = sum
OBJS = main.o sum.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): sum.h
	$(CC) -c $*.c

clean:
	rm $(TARGET) $(OBJS)
