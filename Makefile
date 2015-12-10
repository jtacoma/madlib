SRCS = $(wildcard src/*/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Iinclude -Isrc/internal -std=c11 -g -Wall -Wpedantic -Werror

all: madlib

madlib: $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS)
