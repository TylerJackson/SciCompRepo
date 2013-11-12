/*Tyler Jackson
 * 11/4/2013
 *
 * compare.cpp
 * 		This is a main routine that is designed to compare the time needed to calculate the lagrange
 * 		polynomial versus the time it takes to calculate the newton polynomial.  We adjusted the number
 * 		of intervals as well to see if that would make a difference in runtime.
 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>
#include "mat3.h"

using namespace std;

inline double f(const double x);
double lagrange(Mat &x, Mat &y, double z);
double newton_eval(Mat &x, Mat&c, double z);
int newton_coeffs(Mat &x, Mat&y, Mat&c);


int main(){
	int temp;

	//n = 10, m=1000
	int n=10;
	int m=1000;

	Mat x1 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y1(x1.Cols(),1);
	for(int i=0;i<x1.Cols();i++){
		y1(i)=f(x1(i));
	}
	Mat z1 = Linspace(-1.0, 1.0, m+1);

	Mat p1(m+1,1);						//make matrix for lagrange polynomials

	unsigned int totalMilliseconds = 0;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p1(i) = lagrange(x1,y1,z1(i));
    end = std::chrono::system_clock::now();
    unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 1 ---- n=10, m=1000   : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c1(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x1,y1,c1);
    for (int i=0; i<m; i++)
  	  p1(i) = newton_eval(x1,c1,z1(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   1 ---- n=10, m=1000   : " << totalMilliseconds << " milliseconds" << std::endl;

    //n=10, m=10000
	n=10;
	m=10000;

	Mat x2 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y2(x2.Cols(),1);
	for(int i=0;i<x2.Cols();i++){
		y2(i)=f(x2(i));
	}
	Mat z2 = Linspace(-1.0, 1.0, m+1);

	Mat p2(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p2(i) = lagrange(x2,y2,z2(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 2 ---- n=10, m=10000  : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c2(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x2,y2,c2);
    for (int i=0; i<m; i++)
  	  p2(i) = newton_eval(x2,c2,z2(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   2 ---- n=10, m=10000  : " << totalMilliseconds << " milliseconds" << std::endl;

    //n=10, m=100000
	n=10;
	m=100000;

	Mat x3 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y3(x3.Cols(),1);
	for(int i=0;i<x3.Cols();i++){
		y3(i)=f(x3(i));
	}
	Mat z3 = Linspace(-1.0, 1.0, m+1);

	Mat p3(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p3(i) = lagrange(x3,y3,z3(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 3 ---- n=10, m=100000 : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c3(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x3,y3,c3);
    for (int i=0; i<m; i++)
  	  p3(i) = newton_eval(x3,c3,z3(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   3 ---- n=10, m=100000 : " << totalMilliseconds << " milliseconds" << std::endl;

	//n = 25, m=1000
	n=25;
	m=1000;

	Mat x4 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y4(x4.Cols(),1);
	for(int i=0;i<x4.Cols();i++){
		y4(i)=f(x4(i));
	}
	Mat z4 = Linspace(-1.0, 1.0, m+1);

	Mat p4(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p4(i) = lagrange(x4,y4,z4(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 4 ---- n=25, m=1000   : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c4(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x4,y4,c4);
    for (int i=0; i<m; i++)
  	  p4(i) = newton_eval(x4,c4,z4(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   4 ---- n=25, m=1000   : " << totalMilliseconds << " milliseconds" << std::endl;

    //n=10, m=10000
	n=25;
	m=10000;

	Mat x5 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y5(x5.Cols(),1);
	for(int i=0;i<x5.Cols();i++){
		y5(i)=f(x5(i));
	}
	Mat z5 = Linspace(-1.0, 1.0, m+1);

	Mat p5(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p5(i) = lagrange(x5,y5,z5(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 5 ---- n=25, m=10000  : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c5(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x5,y5,c5);
    for (int i=0; i<m; i++)
  	  p5(i) = newton_eval(x5,c5,z5(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   5 ---- n=25, m=10000  : " << totalMilliseconds << " milliseconds" << std::endl;

    //n=10, m=100000
	n=25;
	m=100000;

	Mat x6 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y6(x6.Cols(),1);
	for(int i=0;i<x6.Cols();i++){
		y6(i)=f(x6(i));
	}
	Mat z6 = Linspace(-1.0, 1.0, m+1);

	Mat p6(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p6(i) = lagrange(x6,y6,z6(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 6 ---- n=25, m=100000 : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c6(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x6,y6,c6);
    for (int i=0; i<m; i++)
  	  p6(i) = newton_eval(x6,c6,z6(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   6 ---- n=25, m=100000 : " << totalMilliseconds << " milliseconds" << std::endl;

	//n = 50, m=1000
	n=50;
	m=1000;

	Mat x7 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y7(x7.Cols(),1);
	for(int i=0;i<x7.Cols();i++){
		y7(i)=f(x7(i));
	}
	Mat z7 = Linspace(-1.0, 1.0, m+1);

	Mat p7(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p7(i) = lagrange(x7,y7,z7(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 7 ---- n=50, m=1000   : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c7(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x7,y7,c7);
    for (int i=0; i<m; i++)
  	  p7(i) = newton_eval(x7,c7,z7(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   7 ---- n=50, m=1000   : " << totalMilliseconds << " milliseconds" << std::endl;

    //n=50, m=10000
	n=50;
	m=10000;

	Mat x8 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y8(x8.Cols(),1);
	for(int i=0;i<x8.Cols();i++){
		y8(i)=f(x8(i));
	}
	Mat z8 = Linspace(-1.0, 1.0, m+1);

	Mat p8(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p8(i) = lagrange(x8,y8,z8(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 8 ---- n=50, m=10000  : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c8(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x8,y8,c8);
    for (int i=0; i<m; i++)
  	  p8(i) = newton_eval(x8,c8,z8(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   8 ---- n=50, m=10000  : " << totalMilliseconds << " milliseconds" << std::endl;

    //n=50, m=100000
	n=50;
	m=100000;

	Mat x9 = Linspace(-1.0, 1.0, n+1);   // set nodes
	Mat y9(x9.Cols(),1);
	for(int i=0;i<x9.Cols();i++){
		y9(i)=f(x9(i));
	}
	Mat z9 = Linspace(-1.0, 1.0, m+1);

	Mat p9(m+1,1);						//make matrix for lagrange polynomials

	totalMilliseconds = 0;
    start = std::chrono::system_clock::now();
	for (int i=0; i<m; i++)
	    p9(i) = lagrange(x9,y9,z9(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Lagrange Time 9 ---- n=50, m=100000 : " << totalMilliseconds << " milliseconds" << std::endl;

    totalMilliseconds = 0;
    Mat c9(n+1,1);							// create coeff. matrix
    start = std::chrono::system_clock::now();
    temp = newton_coeffs(x9,y9,c9);
    for (int i=0; i<m; i++)
  	  p9(i) = newton_eval(x9,c9,z9(i));
    end = std::chrono::system_clock::now();
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Newton Time   9 ---- n=50, m=100000 : " << totalMilliseconds << " milliseconds" << std::endl;


	return 0;

}
// function to interpolate
inline double f(const double x) {
  return (cos(3*x*x));
}
