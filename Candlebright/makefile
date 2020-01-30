CC=g++
COMPILER_FLAGS=	-lm

default: main

main: clean
	$(CC) -c src/main.cpp -o build/main.o
	$(CC) build/main.o -o bin/jogo -lsfml-graphics -lsfml-window -lsfml-system $(COMPILER_FLAGS)

clean:
	rm -rf build/* bin/*

run: clean main
	 ./bin/jogo