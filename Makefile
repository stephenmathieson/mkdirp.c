
test: test.c src/*.c deps/*.c
	$(CC) -std=c99 $^ -o $@ -Ideps -Isrc -Wall
	./test

.PHONY: test
