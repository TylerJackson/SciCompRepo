/*
 * newton.h

 *
 *  Created on: Sep 28, 2013
 *      Author: tgjackson
 */

#include <iostream>
#include <iomanip>
#include <math.h>
double f(double x);
double df(double x);
double newton(double(*f)(const double),double(*df)(const double),double x,int maxit,double tol);

using namespace std;
int main(){
	/*			This main routine uses the Newton method to try and approximate the roots of a function.
	 * 		The  function we use is f(x)= x*(x-3)(x+1).  The Newton method is implemented in newton.cpp.
	 * 		In the implementation we pass in this function and its derivative as well as an initial guess
	 * 		for the value of x.  We allow a maximum number of iterations, for our approximation, and tolerate
	 * 		the approximation to a specified value.
	 *
	 *		Our initial guess for x will either be 2, or -2
	 *		The toleration we will use for our approximation will vary from 10^-2, to 10^-6, to 10^-10
	 *		The maximum number of iterations we will allow is 20.
	 */
		int maxit=20;
		double x;
		double tol;


	cout<<"----------NEWTONS METHOD------------"<<endl;
	cout<<endl;

	//Xo=-2 , tol=10^-2
	x=-2.0;
	tol=.01;
	cout<<"Test 1: When Xo = -2, and tol = 10^-2"<<endl;
	cout<<" our approximation for the root of the function is : "<<endl;
	cout<<"                                                     "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;

	//Xo=-2 , tol=10^-6
	x=-2.0;
	tol=.000001;
	cout<<"Test 2: When Xo = -2, and tol = 10^-6"<<endl;
	cout<<" our approximation for the root of the function is : "<<endl;
	cout<<"                                                     "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;

	//Xo=-2 , tol=10^-10
	x=-2.0;
	tol=pow(10.0,-10.0);
	cout<<"Test 3: When Xo = -2, and tol = 10^-10"<<endl;
	cout<<" our approximation for the root of the function is : "<<endl;
	cout<<"                                                     "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;

	//Xo=2 , tol=10^-2
	x=2.0;
	tol=.01;
	cout<<"Test 4: When Xo = 2, and tol = 10^-2"<<endl;
	cout<<" our approximation for the root of the function is : "<<endl;
	cout<<"                                                     "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=2 , tol=10^-6
	x=2.0;
	tol=.000001;
	cout<<"Test 5: When Xo = 2, and tol = 10^-6"<<endl;
	cout<<" our approximation for the root of the function is : "<<endl;
	cout<<"                                                     "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=2 , tol=10^-10
	x=2.0;
	tol=pow(10.0,-10.0);
	cout<<"Test 6: When Xo = 2, and tol = 10^-10"<<endl;
	cout<<" our approximation for the root of the function is : "<<endl;
	cout<<"                                                     "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	cout<<endl;

	return 0;
}
double f(double x){
	return(x*(x-3.0)*(x+1.0));
}
double df(double x){
	return(3.0*x*x-4.0*x-3.0);
}
