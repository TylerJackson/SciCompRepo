/*Tyler Jackson
 * 11/4/2013
 *
 * runge_regular.cpp
 * 		This class tests my interpolation of the runge function using my lagrange2D method.
 * 	The runge function is considered the worst function when trying to use interpolation.  We
 * 	use uniform nodes for the regular case (this case).
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "mat3.h"

using namespace std;
inline double f(const double x,const double y);
double lagrange2D(Mat &x, Mat &y, Mat &z, double a, double b);

int main(){
	int n=10;
	int m=10;
	Mat x = Linspace(-5.0, 5.0, m+1);   // set nodes
	Mat y = Linspace(-5.0, 5.0, n+1);   // set nodes
	Mat z(m+1,n+1);
	for(int i=0;i<z.Rows();i++){
		for(int j=0;j<z.Cols();j++){
			z(i,j)=f(x(i),y(j));
		}
	}
	Mat a = Linspace(-5.0,5.0, 201);
	Mat b = Linspace(-5.0,5.0, 201);
	char * aval="avals.txt";
	char * bval="bvals.txt";
	a.Write(aval);
	b.Write(bval);

	Mat p10(201,201);
	for(int i=0;i<201;i++){
		for(int j=0;j<201;j++){
			p10(i,j) = lagrange2D(x,y,z,a(i),b(j));
		}
	}
	char * p10file="p10_reg.txt";
	p10.Write(p10file);

	n=20;
	m=20;
	Mat x1 = Linspace(-5.0, 5.0, m+1);   // set nodes
	Mat y1 = Linspace(-5.0, 5.0, n+1);   // set nodes
	Mat z1(m+1,n+1);
	for(int i=0;i<z1.Rows();i++){
		for(int j=0;j<z1.Cols();j++){
			z1(i,j)=f(x1(i),y1(j));
		}
	}
	Mat p20(201,201);
	for(int i=0;i<201;i++){
		for(int j=0;j<201;j++){
			p20(i,j) = lagrange2D(x1,y1,z1,a(i),b(j));
		}
	}
	char * p20file="p20_reg.txt";
	p20.Write(p20file);

	Mat runge(201,201);
	for(int i=0;i<201;i++){
		for(int j=0;j<201;j++){
			runge(i,j)=f(a(i),b(j));
		}
	}
	char * rung="runge.txt";
	runge.Write(rung);

	return 0;
}

// function to interpolate
inline double f(const double x,const double y) {
  return (1.0/(1.0 + x*x + y*y));
}
