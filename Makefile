
test: test.c src/*.c deps/*.c
	$(CC) -std=c99 $^ -o $@ -Ideps
	./test

.PHONY: test
