CC = gcc
CFLAGS = -Wall -g
TARGET = app1
SRCS = index.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)