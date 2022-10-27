CC=g++
CFLAGS=-Wall -Wextra -Werror

.PHONY: all clean rebuild

all: first_part

clean:
	rm -rf *.o *.a *.so *.out ../build/*.so ../build/*.out

first_part: clean main 
	./main.out

task7: clean build_with_dynamic 
	../build/./main.out

main: main.o tasks_curves.o curves.o
	$(CC) main.o tasks_curves.o curves.o -o main.out

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o 

curves.o: curves.h curves.cpp
	$(CC) $(CFLAGS) -c curves.cpp -o curves.o 

tasks_curves.o: tasks_curves.h tasks_curves.cpp
	$(CC) $(CFLAGS) -c tasks_curves.cpp -o tasks_curves.o 

curves.so: curves.h curves.cpp
	$(CC) $(CFLAGS) -fPIC -c  curves.cpp -o curves.o
	$(CC) -shared -o curves.so curves.o -ldl
	rm curves.o
	cp curves.so ../build/curves.so

build_with_dynamic: main.o tasks_curves.o curves.so
	$(CC) main.o tasks_curves.o curves.so -ldl -o ../build/main.out -L. -Wl,-rpath,.

