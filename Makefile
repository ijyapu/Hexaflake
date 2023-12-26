CC = g++
CFLAGS = -std=c++14 -Wall
FIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: Hexa

Hexa: main.o hexa.o
	$(CC) $(CFLAGS) -o $@ $^ $(FIBS)

main.o: main.cpp hexa.hpp
	$(CC) $(CFLAGS) -c $<

hexa.o: hexa.cpp hexa.hpp
	$(CC) $(CFLAGS) -c $<

lint:
	clang-tidy *.cpp -- $(CFLAGS)

clean:
	rm -f *.o Hexa