
CC     ?= cc
SRC     = $(wildcard src/*.c)
SRC    += $(wildcard deps/*/*.c)
CFLAGS  = -std=c99 -Ideps -Isrc
CFLAGS += -Wall -Wextra

test: test.c $(SRC)
	$(CC) $(CFLAGS) $^ -o $@
	./test

clean:
	rm -f test

.PHONY: test