/*Tyler Jackson
 * 11/4/2013
 *
 * 	lagrange2D.cpp
 * 		This file implements my lagrange2D function for interpolation.  This uses the same lagrange basis function
 * 	that was provided to us in lagrange.cpp.  However, now we call it twice (once for x and once for y)
 * 	in our lagrange2D function.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "mat3.h"

using namespace std;


// Utility function to evaluate a given Lagrange basis function at a point.
//
// Usage: l = lagrange_basis(x, i, z);
//
// inputs:   x     Mat vector of length n+1, containing the interpolation nodes
//           i     integer indicating which Lagrange basis function to evaluate
//           z     double location to evaluate basis function
// outputs:  p     value of l(z)
//
double lagrange_basis2D(Mat &x, int i, double z) {
  double l = 1.0;              // initialize basis function
  double *xd = x.get_data();   // access data array (for increased speed)
  for (int j=0; j<x.Rows()*x.Cols(); j++)
    if (j != i)  l *= (z - xd[j]) / (xd[i] - xd[j]);
  return l;
}



// This routine evaluates the Lagrange interpolating polynomial,
// defined over a set of data points (x_i,y_i), i=0,...,n, at a point z.
//
// Usage: p = lagrange(x, y, z);
//
// inputs:   x     Mat vector of length n+1, containing the interpolation nodes
//           y     Mat vector of length n+1, containing the interpolation data
//           z     double location to evaluate polynomial
// outputs:  p     value of p(z)
//
double lagrange2D(Mat &x, Mat &y, Mat&z, double a,double b)
{

  // check input arguments (lengths of x and y)
  if (x.Rows()*x.Cols() != y.Rows()*y.Cols()) {
    cerr << "lagrange2d error: x and y have different lengths!\n";
    return 0.0;
  }

  // get m
  int m = x.Rows()*x.Cols() - 1;

  // get n
  int n = y.Rows()*y.Cols() - 1;

  // evaluate p
  double p = 0.0;                // initialize result
  for(int i=0;i<=m;i++){
	  for (int j=0; j<=n; j++)       // loop over data values
		p += z(i,j)*lagrange_basis2D(x, i, a)*lagrange_basis2D(y, j, b);  // update result with next term
  }
  // return final result
  return p;

} // end of function
