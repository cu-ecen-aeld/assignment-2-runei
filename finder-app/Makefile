CC=gcc
#CC=aarch64_be-none-linux-gnu-gcc

SRCS := writer.c
OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror

.PHONY: all clean

all: writer

writer: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f writer $(OBJS)

