/*Tyler Jackson
 * 11/4/2013
 *
 * test_newton.cpp
 * 		This class tests my newton interpolation method.  I calculate the polynomial with varying
 * 		number of nodes, and then compared the result with the true values to see the error.  I then
 * 		printed the error.  We would expect the error for this method to be similar to the error
 * 		printed out by the test_newton.cpp that was provided to us.
 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "mat3.h"

using namespace std;

// function prototypes
inline double f(const double x);
double newton_eval(Mat &x, Mat&c, double z);
int newton_coeffs(Mat &x, Mat&y, Mat&c);

// This routine tests the function lagrange.cpp over the interval [-1,1].
int main(int argc, char* argv[]) {

  ///////////////
  // first, test with 7 nodes
  int n = 6;                          // set n
  Mat x = Linspace(-1.0, 1.0, n+1);   // set nodes
  Mat c(n+1,1);						  // create coeff. matrix
  Mat y(n+1,1);                       // initialize data
  for (int i=0; i<=n; i++)            // fill data
    y(i) = f(x(i));
  //eval for coefficients
  int temp = newton_coeffs(x,y,c);
  if(temp == 0){
	  cout<<"Coefficients were calculated"<<endl;
  }else{
	  cout<<"There was an error when calculating the coefficients"<<endl;
  }

  // set evaluation points z as midpoints between nodes
  double dx = 2.0/n;                  // set node spacing
  Mat z = Linspace(-1.0+dx/2.0, 1.0-dx/2.0, n);

  // evaluate the polynomial at the points z, storing in p
  Mat p(n,1);
  for (int i=0; i<n; i++)
	  p(i) = newton_eval(x,c,z(i));

  // output errors at each point
  cout << endl << "interpolant and error using " << n+1 << " nodes:\n";
  cout << "      z        f(z)               p(z)              error\n";
  for (int i=0; i<n; i++)
    printf("   %6.3f   %16.13f   %16.13f   %g\n",
	   z(i), f(z(i)), p(i), fabs(f(z(i))-p(i)));

  ///////////////
  // repeate test with 15 nodes
  n = 15;                              // set n
  Mat x2 = Linspace(-1.0, 1.0, n+1);   // set nodes
  Mat c2(n+1,1);						  // create coeff. matrix
  Mat y2(n+1,1);                       // initialize data
  for (int i=0; i<=n; i++)             // fill data
    y2(i) = f(x2(i));

  //eval for coefficients
  int temp2 = newton_coeffs(x2,y2,c2);
  if(temp2 == 0){
	  cout<<"Coefficients were calculated"<<endl;
  }else{
	  cout<<"There was an error when calculating the coefficients"<<endl;
  }

  // set evaluation points z as midpoints between nodes
  dx = 2.0/n;                  // set node spacing
  Mat z2 = Linspace(-1.0+dx/2.0, 1.0-dx/2.0, n);

  // evaluate the polynomial at the points z, storing in p
  Mat p2(n,1);
  for (int i=0; i<n; i++)
    p2(i) = newton_eval(x2,c2,z2(i));

  // output errors at each point
  cout << endl << "interpolant and error using " << n+1 << " nodes:\n";
  cout << "      z        f(z)               p(z)              error\n";
  for (int i=0; i<n; i++)
    printf("   %6.3f   %16.13f   %16.13f   %g\n",
	   z2(i), f(z2(i)), p2(i), fabs(f(z2(i))-p2(i)));

} // end routine


// function to interpolate
inline double f(const double x) {
  return (exp(x*x));
}
