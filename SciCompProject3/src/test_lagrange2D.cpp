/* Daniel R. Reynolds
   SMU Mathematics
   Math 3316
   8 October 2013 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "mat3.h"

using namespace std;

// function prototypes
inline double f(const double x, const double y);
double lagrange2D(Mat &x, Mat &y, Mat &z, double a, double b);


// This routine tests the function lagrange2D.cpp.
int main(int argc, char* argv[]) {

  ///////////////
  // first, test with 7 nodes in each direction
  int m = 6;                          // set m
  int n = 6;                          // set n
  Mat x = Linspace(-2.0, 2.0, m+1);   // set nodes
  Mat y = Linspace(-2.0, 2.0, n+1);
  Mat z(m+1,n+1);                     // initialize data
  for (int j=0; j<=n; j++)  
    for (int i=0; i<=m; i++)
      z(i,j) = f(x(i),y(j));          // fill data

  // set evaluation points (a,b) as a fine mesh over the domain
  Mat a = Linspace(-2.0, 2.0, 100);
  Mat b = Linspace(-2.0, 2.0, 100);

  // output evaluation points to disk
  a.Write("a.txt");
  b.Write("b.txt");
  
  // evaluate the polynomial at the points (a,b), storing in p
  Mat p(100,100);
  for (int j=0; j<100; j++) 
    for (int i=0; i<100; i++) 
      p(i,j) = lagrange2D(x,y,z,a(i),b(j));

  // output p to disk
  p.Write("p6.txt");

  // evaluate the true function at the points (a,b), storing in ftrue
  Mat ftrue(100,100);
  for (int j=0; j<100; j++) 
    for (int i=0; i<100; i++) 
      ftrue(i,j) = f(a(i),b(j));

  // output true function to disk
  ftrue.Write("ftrue.txt");


  ///////////////
  // repeate test with 15 nodes in each direction
  m = 14;                              // set m
  n = 14;                              // set n
  Mat x2 = Linspace(-2.0, 2.0, m+1);   // set nodes
  Mat y2 = Linspace(-2.0, 2.0, n+1);
  Mat z2(m+1,n+1);                     // initialize data
  for (int j=0; j<=n; j++)  
    for (int i=0; i<=m; i++)
      z2(i,j) = f(x2(i),y2(j));        // fill data

  // evaluate the polynomial at the points (a,b), storing back in p
  for (int j=0; j<100; j++) 
    for (int i=0; i<100; i++) 
      p(i,j) = lagrange2D(x2,y2,z2,a(i),b(j));

  // output p to disk
  p.Write("p15.txt");

} // end routine


// function to interpolate
inline double f(const double x, const double y) {
  return (sin(x)*cos(2.0*y));
}

