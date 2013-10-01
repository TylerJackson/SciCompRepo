/*
 * main.cpp
 *
 *  Created on: Sep 30, 2013
 *      Author: tgjackson
 */

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f(double x);
double fV(double V);
double df(double x);
double dfV(double V);
double dplusf(double x);
double dplusfV(double x);
double newton (double(*f)(const double),double(*df)(const double),
		double x,int maxit,double tol);
double fd_newton (double(*f)(const double),double(*df)(const double),
		double x,int maxit,double tol,double alpha);
double newtonV (double(*f)(const double),double(*df)(const double),
		double V,int maxit,double tol);
double fd_newtonV (double(*f)(const double),double(*df)(const double),
		double V,int maxit,double tol,double alpha);
double bisection(double (*f)(const double), double a,
		double b, int maxit, double tol);



int main(){



	//first test if Newton's method finds the roots
	cout<<"----------NEWTONS METHOD------------"<<endl;
	cout<<endl;
	// tests will vary based on Xo=-2, or 2
	// tests will vary based on tolerance =10^-2, 10^-6, 10^-10
	// maximum iterations will be 20
	double maxit=20;
	double x;
	double tol;
	//Xo=-2 , tol=10^-2
	x=-2.0;
	tol=.01;
	cout<<"The root for initial x=-2, with a tolerance of 10^-2 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=-2 , tol=10^-6
	x=-2.0;
	tol=.000001;
	cout<<"The root for initial x=-2, with a tolerance of 10^-6 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=-2 , tol=10^-10
	x=-2.0;
	tol=pow(10.0,-10.0);
	cout<<"The root for initial x=-2, with a tolerance of 10^-10 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=2 , tol=10^-2
	x=2.0;
	tol=.01;
	cout<<"The root for initial x=2, with a tolerance of 10^-2 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=2 , tol=10^-6
	x=2.0;
	tol=.000001;
	cout<<"The root for initial x=2, with a tolerance of 10^-6 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=2 , tol=10^-10
	x=2.0;
	tol=pow(10.0,-10.0);
	cout<<"The root for initial x=-2, with a tolerance of 10^-10 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	cout<<endl;




	//next test if Newton's forward difference method finds the roots
	cout<<"----------NEWTONS FORWARD DIFFERENCE METHOD------------"<<endl;
	cout<<endl;
	// tests will vary based on Xo=-2, or 2
	// tests will vary based on tolerance =10^-2, 10^-6, 10^-10
	// tests will vary based on alpha =2^-6, 2^-26, 2^-48
	// maximum iterations will be 20
	double alpha;
	//Xo=-2 , tol=10^-2, alpha=2^-6
	x=-2.0;
	tol=.01;
	alpha=pow(2.0,-6.0);
	cout<<"The root for initial x=-2, tolerance of 10^-2, and alpha = 2^-6 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-6, alpha=2^-6
	x=-2.0;
	tol=.000001;
	alpha=pow(2.0,-6.0);
	cout<<"The root for initial x=-2, tolerance of 10^-6, and alpha = 2^-6 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-10, alpha=2^-6
	x=-2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-6.0);
	cout<<"The root for initial x=-2, tolerance of 10^-10, and alpha = 2^-6 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-2, alpha=2^-6
	x=2.0;
	alpha=pow(2.0,-6.0);
	tol=.01;
	cout<<"The root for initial x=2, tolerance of 10^-2, and alpha = 2^-6 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-6, alpha=2^-6
	x=2.0;
	tol=.000001;
	alpha=pow(2.0,-6.0);
	cout<<"The root for initial x=2, tolerance of 10^-6, and alpha = 2^-6 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-10, alpha=2^-6
	x=2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-6.0);
	cout<<"The root for initial x=-2, tolerance of 10^-10, and alpha = 2^-6 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;


	//Xo=-2 , tol=10^-2, alpha=2^-26
	x=-2.0;
	tol=.01;
	alpha=pow(2.0,-26.0);
	cout<<"The root for initial x=-2, tolerance of 10^-2, and alpha = 2^-26 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-6, alpha=2^-26
	x=-2.0;
	tol=.000001;
	alpha=pow(2.0,-26.0);
	cout<<"The root for initial x=-2, tolerance of 10^-6, and alpha = 2^-26 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-10, alpha=2^-26
	x=-2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-26.0);
	cout<<"The root for initial x=-2, tolerance of 10^-10, and alpha = 2^-26 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-2, alpha=2^-26
	x=2.0;
	alpha=pow(2.0,-26.0);
	tol=.01;
	cout<<"The root for initial x=2, tolerance of 10^-2, and alpha = 2^-26 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-6, alpha=2^-26
	x=2.0;
	tol=.000001;
	alpha=pow(2.0,-26.0);
	cout<<"The root for initial x=2, tolerance of 10^-6, and alpha = 2^-26 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-10, alpha=2^-26
	x=2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-26.0);
	cout<<"The root for initial x=-2, tolerance of 10^-10, and alpha = 2^-26 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;


	//Xo=-2 , tol=10^-2, alpha=2^-48
	x=-2.0;
	tol=.01;
	alpha=pow(2.0,-48.0);
	cout<<"The root for initial x=-2, tolerance of 10^-2, and alpha = 2^-48 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-6, alpha=2^-48
	x=-2.0;
	tol=.000001;
	alpha=pow(2.0,-48.0);
	cout<<"The root for initial x=-2, tolerance of 10^-6, and alpha = 2^-48 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=-2 , tol=10^-10, alpha=2^-48
	x=-2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-48.0);
	cout<<"The root for initial x=-2, tolerance of 10^-10, and alpha = 2^-48 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-2, alpha=2^-48
	x=2.0;
	alpha=pow(2.0,-48.0);
	tol=.01;
	cout<<"The root for initial x=2, tolerance of 10^-2, and alpha = 2^-48 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-6, alpha=2^-48
	x=2.0;
	tol=.000001;
	alpha=pow(2.0,-48.0);
	cout<<"The root for initial x=2, tolerance of 10^-6, and alpha = 2^-48 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	//Xo=2 , tol=10^-10, alpha=2^-48
	x=2.0;
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-48.0);
	cout<<"The root for initial x=-2, tolerance of 10^-10, and alpha = 2^-48 is:";
	cout<<"    "<<setprecision(10)<<fd_newton(f,df,x,maxit,tol,alpha);
	cout<<endl;
	cout<<endl;





	//find V roots using bisection
	cout<<"-----------FIND ROOTS OF f(V) USING BISECTION-----------"<<endl;
	cout<<endl;
	// tests will vary based on tolerance =10^-5, 10^-8, 10^-11
	// maximum iterations will be 1000

	double V=.75;
	double a=.5;
	double b=1.0;
	maxit=1000.0;
	//Xo=-2 , tol=10^-2
	x=-2.0;
	tol=.01;
	cout<<"The root for initial x=-2, with a tolerance of 10^-2 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=-2 , tol=10^-6
	x=-2.0;
	tol=.000001;
	cout<<"The root for initial x=-2, with a tolerance of 10^-6 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;
	//Xo=-2 , tol=10^-10
	x=-2.0;
	tol=pow(10.0,-10.0);
	cout<<"The root for initial x=-2, with a tolerance of 10^-10 is:";
	cout<<"    "<<setprecision(10)<<newton(f,df,x,maxit,tol);
	cout<<endl;

	//
	return 0;
}
double f(double x){
	return(x*(x-3.0)*(x+1.0));
}
double fV(double V){
	double q=1.6022*pow(10.0,-19.0);
	double Kb=1.3806*pow(10.0,-23.0);
	double Voc=.8;
	double T=315.0;
	return (exp( (q*V)/(Kb*T) )*(1 + (q*V)/(Kb*T)) -exp( (q*Voc)/(Kb*T) ));
}
double df(double x){
	return(3.0*x*x-4.0*x-3.0);
}
double dfV(double V){
	double q=1.6022*pow(10.0,-19.0);
	double Kb=1.3806*pow(10.0,-23.0);
	double T=315.0;
	return (exp( (q*V)/(Kb*T) )*(1 + (q*V)/(Kb*T))*(q/(Kb*T)) +exp( (q*V)/(Kb*T) )*(q/(Kb*T)));
}
double dplusf(double x,double alpha){
	return ((f(x+alpha)-f(x))/alpha);
}
double dplusfV(double x,double alpha){
	return ((fV(x+alpha)-fV(x))/alpha);
}
double newton (double(*f)(const double),double(*df)(const double),
		double x,int maxit,double tol){
	cout<<endl;
	double h=0;
	for(int k=1;k<=maxit;k++){
		h=f(x)/df(x);
		x=x-h;
		if(fabs(h)<tol)
			break;
	}
	cout<<"    error:  "<<fabs(f(x))<<endl;
	return x;
}
double fd_newton (double(*f)(const double),double(*dplusf)(const double),
		double x,int maxit,double tol,double alpha){
	cout<<endl;
	double h=0;
	for(int k=1;k<=maxit;k++){
		h=f(x)/dplusf(x);
		x=x-h;
		if(fabs(h)<tol)
			break;
	}
	cout<<"    error:  "<<fabs(f(x))<<endl;
	return x;
}
double newtonV (double(*fV)(const double),double(*dfV)(const double),
		double V,int maxit,double tol){
	cout<<endl;
	double h=0;
	for(int k=1;k<=maxit;k++){
		h=fV(V)/dfV(V);
		V=V-h;
		if(fabs(h)<tol)
			break;
	}
	cout<<"    error:  "<<fabs(fV(V))<<endl;
	return V;
}
double fd_newtonV (double(*fV)(const double),double(*dplusfV)(const double),
		double V,int maxit,double tol,double alpha){
	cout<<endl;
	double h=0;
	for(int k=1;k<=maxit;k++){
		h=fV(V)/dplusfV(V);
		V=V-h;
		if(fabs(h)<tol)
			break;
	}
	cout<<"    error:  "<<fabs(fV(V))<<endl;
	return V;
}
double bisection(double (*f)(const double), double a,
		double b, int maxit, double tol) {

	  // initialize approximate solution
	  double c = 0.5*(a+b);

	  // check input arguments
	  if (maxit < 1) {
	    cerr << "warning: maxit = " << maxit << " < 1. Resetting to 100\n";
	    maxit = 100;
	  }
	  if (a >= b) {
	    cerr << "error: illegal interval [" << a << ", " << b << "]!\n";
	    return 0.0;
	  }
	  if (tol < 1.e-15) {
	    cerr << "warning: tol is too small, resetting to 1e-15\n";
	    tol = 1.e-15;
	  }

	  // get initial function values, check whether root exists in interval
	  double fa = f(a);
	  double fb = f(b);
	  if (fa*fb > 0.0) {
	    cerr << "error: illegal interval, f(a)=" << fa << ", f(b)=" << fb << endl;
	    return 0.0;
	  }

	  // begin iteration
	  double fc, err=0.5*(b-a);
	  cout << endl << " Bisection Method: initial |(b-a)/2| = " << err << endl;
	  for (int i=0; i<maxit; i++) {

	    // evaluate function at c
	    fc = f(c);

	    // update interval
	    if (fa*fc < 0.0) {
	      b = c;
	      fb = fc;
	    } else {
	      a = c;
	      fa = fc;
	    }

	    // compute updated guess, function value
	    c = 0.5*(a+b);

	    // check for convergence and output diagnostics
	    err = 0.5*(b-a);
	    cout << "   iter " << i << ", [" << a << "," << b
		 << "], |(b-a)/2| = " << err << endl;
	    if (err < tol)  break;

	  } // end loop

	  // return final result
	  return c;

	} // end of function

