# target executable name
TARGET 	= testprog

# compiler settings
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Wpedantic
LFLAGS 	= -lm

all: $(TARGET)
	@:

run: $(TARGET)
	@./$(TARGET)

$(TARGET): test.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	rm -rf *.o $(TARGET)

.PHONY: all clean run
