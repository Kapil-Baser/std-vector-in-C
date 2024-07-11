CC = clang
FLAGS = -Wall -Werror -Wextra -g
CFILES = main.c vector.c
OBJECTS = main.o vector.o

BINARY = vector

all: $(BINARY)


$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^


%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $^