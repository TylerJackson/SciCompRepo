####################################################
#
#               makefile for Project 3
#
#               Tyler Jackson
#               Math 3316
#               11/5/2013
####################################################


# make file targets

all:	test_lagrange2D.exe test_lagrange.exe test_newton.exe runge_regular.exe runge_chebyshev.exe compare.exe

test_lagrange2D.exe : test_lagrange2D.cpp lagrange2D.cpp mat3.cpp
		g++ $^ -o $@

test_lagrange.exe : test_lagrange.cpp lagrange.cpp	mat3.cpp
		g++ $^ -o $@

test_newton.exe : test_newton.cpp newton_interp.cpp mat3.cpp
		g++ $^ -o $@

runge_regular.exe : runge_regular.cpp lagrange2D.cpp mat3.cpp
		g++ $^ -o $@
                
runge_chebyshev.exe : runge_chebyshev.cpp lagrange2D.cpp mat3.cpp
		g++ $^ -o $@
              
compare.exe : compare.cpp lagrange.cpp newton_interp.cpp mat3.cpp
		g++ $^ -o $@ -std=c++11
		
                
clean : 
		\rm -f *.exe *~

realclean : clean
		\rm -f *.exe *~

############ End of Makefile ##############
                