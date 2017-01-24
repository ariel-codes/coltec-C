TARGET = aula8.bin
LIBS =
CC = gcc
CFLAGS = -O2 -Wall -w -Wextra

.PHONY: clean all default

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall -Wextra -O2 $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
