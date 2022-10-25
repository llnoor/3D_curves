CC=g++
CFLAGS=-Wall -Wextra -Werror

.PHONY: all clean rebuild

all: main

clean:
	rm -rf *.o *.a *.so *.out

main: main.o curves.o
	$(CC) main.o curves.o -o main.out

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o 

curves.o: curves.h curves.cpp
	$(CC) $(CFLAGS) -c curves.cpp -o curves.o 