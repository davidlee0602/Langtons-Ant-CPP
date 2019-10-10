#makefile created for project 1 (CS162) Langton's Ant
#referenced makefile create guide from "Paul Programming - youtube video":
#https://www.youtube.com/watch?v=_r7i5X0rXJk

all: langtons

langtons: main.o Ant.o Input.o Menu.o
	g++ -std=c++11 main.o Ant.o Input.o Menu.o -o langtons

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Ant.o: Ant.cpp
	g++ -std=c++11 -c Ant.cpp

Input.o: Input.cpp
	g++ -std=c++11 -c Input.cpp

Menu.o: Menu.cpp
	g++ -std=c++11 -c Menu.cpp
	
clean:
	rm *.o langtons

