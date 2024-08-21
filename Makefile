CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC = main.c builtins.c execute.c input.c helpers.c loop.c
OBJ = $(SRC:.c=.o)
TARGET = hsh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
