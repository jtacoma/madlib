SRCS = $(wildcard src/*/*.c)
OBJS = $(SRCS:.c=.o)
LOBJS = $(SRCS:.c=.lo)
CFLAGS = -Iinclude -Isrc/internal -std=c11 -g -Wall -Wpedantic -Werror

all: madlib libmadlib.a libmadlib.so

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

%.lo: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -fPIC -o $@ $^

madlib: $(OBJS)
	$(CC) -o $@ $^

libmadlib.a: $(filter-out main,$(OBJS))
	$(AR) rcs $@ $^

libmadlib.so: $(filter-out main,$(LOBJS))
	$(CC) -shared -o $@ $^

clean:
	rm -f $(OBJS) $(LOBJS) main libmadlib.a libmadlib.so
