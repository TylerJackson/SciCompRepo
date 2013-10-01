#makefile Tyler Jackson

-include ./*
# makefile targets
all: Project1.o Mat.o
	g++ -o Project1 Project1.o

Project1: Project1.o Mat.o
	g++ -o Project1 Project1.o

Project2: Project2.o Mat.o
	g++ -o Project2 Project2.o

Project1.o:
	g++ -c ./Project1.cpp

Project2.o: Project2.cpp Project2.h
	g++ -c ./Project2.cpp

Mat.o: Mat.cpp Mat.h 
	g++ -c ./Mat.cpp

clean :
	\rm -f *.o *.out
