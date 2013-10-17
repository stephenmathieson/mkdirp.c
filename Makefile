
test: test.c src/*.c
	$(CC) -std=c99 $^ -o $@
	./test

.PHONY: test
