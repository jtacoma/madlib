SRCS = $(wildcard src/*/*.c)
OBJS = $(SRCS:.c=.o)
CC = clang-3.8
CFLAGS = -Iinclude -std=c11 -g -Wall -Wpedantic -Werror

all: madlib

madlib: $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS)
