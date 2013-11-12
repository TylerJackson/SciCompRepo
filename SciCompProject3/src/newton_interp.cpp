/*Tyler Jackson
 * 11/4/2013
 *
 * newton_interp.cpp
 * 		This class implements newtons method for interpolation.  In order to do this I first calculated
 * 	the coefficients by creating a lower triangular matrix like we discussed in lecture.  Then I
 * 	performed forward substitution using the matrix class provided to solve for the coefficients.  Once I
 * 	had the coefficients I could calculate the polynomial.
 */

#include "mat3.h"
#include <iostream>

using namespace std;

int newton_coeffs(Mat &x, Mat&y, Mat&c){
	x.Trans();
	Mat B(x.Rows(), x.Rows());
	for(int i=0;i<x.Rows();i++){
		B(0,i)=0;
		B(i,0)=1;
	}
	for(int i=1;i<B.Rows();i++){
		for(int j=1;j<=i;j++){
				B(i,j)=1.0;
			for(int m=0;m<j;m++){
				B(i,j)=B(i,j)*(x(i)-x(m));
			}
		}
	}
	FwdSub(B,c,y);

	//simple check to see if the dimensions are all equal, if they are not, the coefficients
	//were calculated incorrectly--not perfect check, but not horrible
	if(c.Rows() == x.Rows()){
	return 0;
	}
	else
		return 1;
}
double newton_eval(Mat &x, Mat&c, double z){
	double answer=0;
	Mat w(x.Rows(),1);
	w(0,0)=c(0,0);
	for(int i=1;i<x.Rows();i++){
		double multFactor=1.0;
		for(int j=0;j<i;j++){
			multFactor=multFactor*(z-x(j,0));
		}
		w(i,0)=c(i,0)*multFactor;
	}
	for(int i=0;i<w.Rows();i++){
		answer=answer+w(i);
	}
	return answer;
}
