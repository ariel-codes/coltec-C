TARGET = Q1.bin
TEST_T = debug.out
LIBS = 
CC = gcc
CFLAGS = -O2 -Wall -w -Wextra

.PHONY: remove test all default

default: $(TARGET)

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall -Wextra -O2 -fomit-frame-pointer $(LIBS) -o $@
	-rm -f *.o

test: $(TEST_T)

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TEST_T) $(OBJECTS)

$(TEST_T): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall -Wextra $(LIBS) -o $@
	./$(TEST_T)

remove:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f $(TEST_T)
