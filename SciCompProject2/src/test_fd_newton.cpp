/*

 *
 *  Created on: Sep 28, 2013
 *      Author: tgjackson
 */

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f(const double x);
double fd_newton (double(*f)(const double),double x,int maxit,double tol,double alpha);

int main(){
	/*			This main routine uses the Newton Forward Difference method to try and
	 * 		approximate the roots of a function.  The function we use is f(x)= x*(x-3)(x+1).
	 * 		The Newton forward difference method is implemented in fd_newton.cpp.  In the
	 * 		implementation we pass in this function and the forward finite difference
	 * 		approximation for its derivative.  We also pass in an initial guess
	 * 		for the value of x.  We allow a maximum number of iterations, for our approximation,
	 * 		and tolerate the approximation to a specified value.  In order to calculate the
	 * 		forward finite difference approximation for the derivative we pass in a specified alpha.
	 *
	 *		Our initial guess for x will either be 2, or -2
	 *		The toleration we will use for our approximation will vary from 10^-2, to 10^-6, to 10^-10
	 *		The value of alpha will vary based from 2^-6, to 2^-26, to 2^-48
	 *		The maximum number of iterations we will allow is 20.
	 */

		int maxit=20;
		double x;
		double tol;
		double alpha;

	cout<<"----------NEWTONS FORWARD DIFFERENCE METHOD------------"<<endl;
	cout<<endl;

	//Xo=-2 , tol=10^-2, alpha=2^-6
	x=-2.0;
	tol=.01;
	alpha=pow(2.0,-6.0);
	cout<<"Test 1: When Xo = -2, and tol = 10^-2,"<<endl;
	cout<<" and alpha = 2^-6, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-6, alpha=2^-6
	x=-2.0;
	tol=.000001;
	alpha=pow(2.0,-6.0);
	cout<<"Test 2: When Xo = -2, and tol = 10^-6,"<<endl;
	cout<<" and alpha = 2^-6, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-10, alpha=2^-6
	x=-2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-6.0);
	cout<<"Test 3: When Xo = -2, and tol = 10^-10,"<<endl;
	cout<<" and alpha = 2^-6, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-2, alpha=2^-6
	x=2.0;
	alpha=pow(2.0,-6.0);
	tol=.01;
	cout<<"Test 4: When Xo = 2, and tol = 10^-2,"<<endl;
	cout<<" and alpha = 2^-6, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-6, alpha=2^-6
	x=2.0;
	tol=.000001;
	alpha=pow(2.0,-6.0);
	cout<<"Test 5: When Xo = 2, and tol = 10^-6,"<<endl;
	cout<<" and alpha = 2^-6, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-10, alpha=2^-6
	x=2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-6.0);
	cout<<"Test 6: When Xo = 2, and tol = 10^-10,"<<endl;
	cout<<" and alpha = 2^-6, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;


	//Xo=-2 , tol=10^-2, alpha=2^-26
	x=-2.0;
	tol=.01;
	alpha=pow(2.0,-26.0);
	cout<<"Test 7: When Xo = -2, and tol = 10^-2,"<<endl;
	cout<<" and alpha = 2^-26, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-6, alpha=2^-26
	x=-2.0;
	tol=.000001;
	alpha=pow(2.0,-26.0);
	cout<<"Test 8: When Xo = -2, and tol = 10^-6,"<<endl;
	cout<<" and alpha = 2^-26, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-10, alpha=2^-26
	x=-2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-26.0);
	cout<<"Test 9: When Xo = -2, and tol = 10^-10,"<<endl;
	cout<<" and alpha = 2^-26, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-2, alpha=2^-26
	x=2.0;
	alpha=pow(2.0,-26.0);
	tol=.01;
	cout<<"Test 10: When Xo = 2, and tol = 10^-2,"<<endl;
	cout<<" and alpha = 2^-26, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-6, alpha=2^-26
	x=2.0;
	tol=.000001;
	alpha=pow(2.0,-26.0);
	cout<<"Test 11: When Xo = 2, and tol = 10^-6,"<<endl;
	cout<<" and alpha = 2^-26, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-10, alpha=2^-26
	x=2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-26.0);
	cout<<"Test 12: When Xo = 2, and tol = 10^-10,"<<endl;
	cout<<" and alpha = 2^-26, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;


	//Xo=-2 , tol=10^-2, alpha=2^-48
	x=-2.0;
	tol=.01;
	alpha=pow(2.0,-48.0);
	cout<<"Test 13: When Xo = -2, and tol = 10^-2,"<<endl;
	cout<<" and alpha = 2^-48, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-6, alpha=2^-48
	x=-2.0;
	tol=.000001;
	alpha=pow(2.0,-48.0);
	cout<<"Test 14: When Xo = -2, and tol = 10^-6,"<<endl;
	cout<<" and alpha = 2^-48, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-10, alpha=2^-48
	x=-2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-48.0);
	cout<<"Test 15: When Xo = -2, and tol = 10^-10,"<<endl;
	cout<<" and alpha = 2^-48, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-2, alpha=2^-48
	x=2.0;
	alpha=pow(2.0,-48.0);
	tol=.01;
	cout<<"Test 16: When Xo = 2, and tol = 10^-2,"<<endl;
	cout<<" and alpha = 2^-48, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-6, alpha=2^-48
	x=2.0;
	tol=.000001;
	alpha=pow(2.0,-48.0);
	cout<<"Test 17: When Xo = 2, and tol = 10^-6,"<<endl;
	cout<<" and alpha = 2^-48, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-10, alpha=2^-48
	x=2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-48.0);
	cout<<"Test 18: When Xo = 2, and tol = 10^-10,"<<endl;
	cout<<" and alpha = 2^-48, our approximation"<<endl;
	cout<<" for the root of the function is : "<<endl;
	cout<<"                                          "<<setprecision(10)<<fd_newton(f,x,maxit,tol,alpha);
	cout<<endl;
	cout<<endl;


	return 0;
}
double f(const double x){
	return(x*(x-3.0)*(x+1.0));
}
