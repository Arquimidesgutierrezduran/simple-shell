CC=gcc

all:
	mkdir ./build/
	$(CC) -c ./src/core.c -o ./build/core.o
	ar rcs ./bin/libshell.a ./build/core.o
	gcc ./src/main.c -o ./bin/main -L./bin -lshell
	rm -rf ./build/

run:
	./bin/main
