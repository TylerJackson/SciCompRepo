####################################################
#
#		makefile for Project 2
#
#		Tyler Jackson
#		Math 3316
#		10/7/2013
####################################################


# make file targets

all:	test_newton.exe test_fd_newton.exe application.exe

test_newton.exe : test_newton.cpp newton.cpp
		g++ $^ -o $@

test_fd_newton.exe : test_fd_newton.cpp fd_newton.cpp
		g++ $^ -o $@
		
application.exe : application.cpp newton.cpp fd_newton.cpp bisection.cpp
		g++ $^ -o $@
		
clean : 
		\rm -f *.exe *~

realclean : clean
		\rm -f *.exe *~
		
############ End of Makefile ##############