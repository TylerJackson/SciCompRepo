/*Tyler Jackson
 * 11/4/2013
 *
 * runge_chebyshev.cpp
 * 		This class tests my interpolation of the runge function using my lagrange2D method.
 * 	However, instead of using uniformly spaced nodes, I created nodes using the chebyshev function.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "mat3.h"

using namespace std;
double f(const double x,const double y);
double chebyNodes(const double i,const double m);
double lagrange2D(Mat &x, Mat &y, Mat &z, double a, double b);

int main(){
	int n=10;
	int m=10;
	Mat x(m+1,1);
	Mat y(n+1,1);
	for(int i=0;i<m+1;i++){
		x(i)=chebyNodes(i,m);
		y(i)=chebyNodes(i,n);
	}
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
	for(int i=0;i<p10.Rows();i++){
		for(int j=0;j<p10.Cols();j++){
			p10(i,j)=lagrange2D(x,y,z,a(i),b(j));
		}
	}
	char * p10file="p10_cheb.txt";
	p10.Write(p10file);

	n=20;
	m=20;
	Mat x1(m+1,1);
	Mat y1(n+1,1);
	for(int i=0;i<m+1;i++){
		x1(i)=chebyNodes(i,m);
		y1(i)=chebyNodes(i,n);
	}
	Mat z1(m+1,n+1);
	for(int i=0;i<z1.Rows();i++){
		for(int j=0;j<z1.Cols();j++){
			z1(i,j)=f(x1(i),y1(j));
		}
	}
	Mat p20(201,201);
	for(int i=0;i<p20.Rows();i++){
		for(int j=0;j<p20.Cols();j++){
			p20(i,j)=lagrange2D(x1,y1,z1,a(i),b(j));
		}
	}
	char * p20file="p20_cheb.txt";
	p20.Write(p20file);

	Mat runge(201,201);
	for(int i=0;i<runge.Rows();i++){
		for(int j=0;j<runge.Cols();j++){
			runge(i,j)=f(a(i),b(j));
		}
	}

	char * runge1="runge.txt";
	runge.Write(runge1);

	x.Write("chebyNodes.txt");
	return 0;
}

// function to interpolate
inline double chebyNodes(const double i,const double m) {

  return (5.0*cos((2.0*i+1.0)*PI /  (2.0*m + 2.0 ) )  );
}

inline double f(const double x,const double y) {
  return (1.0/(1.0 + x*x + y*y));
}
