#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double fV(double V);
double dfV(double V);
double fd_newton (double(*f)(const double),double x,int maxit,double tol,double alpha);
double newton(double(*f)(const double),double(*df)(const double),double x,int maxit,double tol);
double bisection(double (*f)(const double), double a,double b, int maxit, double tol);

int main(){
	/*			This main routine looks at an equation for power output of a solar cell based on
	 * 		the voltage the cell puts out.  We want to calculate the voltage that will results in
	 * 		the maximum power output.  In order to do this we look at our equation for maximum
	 * 		power output provided in the lab.  We then set this equation equal to zero and solve
	 * 		for V to see which values result in the max output.  By setting it equal to zero,
	 * 		we can solve for V by using our three root finding methods (bisection,newton's,newton's
	 * 		forward difference).  We implemented newtons method in newton.cpp, newton's forward
	 * 		difference in fd_newton.cpp, bisection in bisection.cpp.  Our bisection implementation is
	 * 		just the one provided on the website.
	 *
	 *		Our initial guess for V will be .75.
	 *		The toleration we will use for our approximation will vary from 10^-5, to 10^-8, to 10^-11
	 *		The value of alpha will vary based from 2^-6, to 2^-26, to 2^-48
	 *		The maximum number of iterations we will allow is 1000 for bisection and 30 for the other 2.
	 *		For bisection the range for the interval will be .5 < V < 1
	 */

		int maxit=1000;
		double V=.75;
		double a=.5;
		double b=1.0;
		double tol;
		double alpha;

	cout<<"-----------FIND ROOTS OF f(V) USING BISECTION-----------"<<endl;
	cout<<endl;

	//tol=10^-2
	tol=.01;
	cout<<"TEST 1: "<<endl;
	cout<<"The root for initial V= .75,"<<endl;
	cout<<" with a tolerance of 10^-2 is:"<<endl;
	cout<<"                                  "<<setprecision(10)<<bisection(fV,a,b,maxit,tol)<<endl;
	//tol=10^-6
	tol=.000001;
	cout<<"TEST 2: "<<endl;
	cout<<"The root for initial V= .75,"<<endl;
	cout<<" with a tolerance of 10^-6 is:"<<endl;
	cout<<"                                  "<<setprecision(10)<<bisection(fV,a,b,maxit,tol)<<endl;
	//tol=10^-10
	tol=pow(10.0,-10.0);
	cout<<"TEST 3: "<<endl;
	cout<<"The root for initial V= .75,"<<endl;
	cout<<" with a tolerance of 10^-10 is:"<<endl;
	cout<<"                                   "<<setprecision(10)<<bisection(fV,a,b,maxit,tol)<<endl;
	cout<<endl;

	cout<<"-----------FIND ROOTS OF f(V) USING NEWTON'S METHOD-----------"<<endl;
	cout<<endl;
	// maximum iterations will be 30

	maxit=30.0;
	//tol=10^-2
	tol=.01;
	cout<<"TEST 4: "<<endl;
	cout<<"The root for initial V= .75 ,"<<endl;
	cout<<" with a tolerance of 10^-2 is:"<<endl;
	cout<<"                                  "<<setprecision(10)<<newton(fV,dfV,V,maxit,tol)<<endl;
	//tol=10^-6
	tol=.000001;
	cout<<"TEST 5: "<<endl;
	cout<<"The root for initial V= .75,"<<endl;
	cout<<" with a tolerance of 10^-6 is:"<<endl;
	cout<<"                                  "<<setprecision(10)<<newton(fV,dfV,V,maxit,tol)<<endl;
	//tol=10^-10
	tol=pow(10.0,-10.0);
	cout<<"TEST 6: "<<endl;
	cout<<"The root for initial V= .75,"<<endl;
	cout<<" with a tolerance of 10^-10 is:"<<endl;
	cout<<"                                  "<<setprecision(10)<<newton(fV,dfV,V,maxit,tol)<<endl;


	cout<<endl;

	cout<<"-----------FIND ROOTS OF f(V) USING FORWARD DIFFERENCE NEWTON'S METHOD-----------"<<endl;
	cout<<endl;

	//tol=10^-2, alpha= 2^-6
	tol=.01;
	alpha=pow(2.0,-6.0);
	cout<<"TEST 7: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2^-6,"<<endl;
	cout<<" with a tolerance of 10^-2 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-2, alpha= 2^-26
	tol=.01;
	alpha=pow(2.0,-26.0);
	cout<<"TEST 8: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2^-26,"<<endl;
	cout<<"with a tolerance of 10^-2 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV, V,maxit,tol,alpha)<<endl;
	//tol=10^-2, alpha= 2^-48
	tol=.01;
	alpha=pow(2.0,-48.0);
	cout<<"TEST 9: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2-48,"<<endl;
	cout<<"with a tolerance of 10^-2 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-6, alpha= 2^-6
	tol=pow(10.0,-6.0);
	alpha=pow(2.0,-6.0);
	cout<<"TEST 10: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2^-6,"<<endl;
	cout<<" with a tolerance of 10^-6 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-6, alpha= 2^-26
	tol=.000001;
	alpha=pow(2.0,-26.0);
	cout<<"TEST 11: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2^-26,"<<endl;
	cout<<" with a tolerance of 10^-6 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-6, alpha= 2^-48
	tol=pow(10.0,-6.0);
	alpha=pow(2.0,-48.0);
	cout<<"TEST 12: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2-48,"<<endl;
	cout<<" with a tolerance of 10^-6 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-10, alpha= 2^-6
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-6.0);
	cout<<"TEST 13: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2^-6,"<<endl;
	cout<<" with a tolerance of 10^-10 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-10, alpha= 2^-26
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-26.0);
	cout<<"TEST 14: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2^-26,"<<endl;
	cout<<" with a tolerance of 10^-10 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;
	//tol=10^-10, alpha= 2^-48
	tol=pow(10.0,-10.0);
	alpha=pow(2.0,-48.0);
	cout<<"TEST 15: "<<endl;
	cout<<"The root for initial V= .75 , alpha is 2-48,"<<endl;
	cout<<" with a tolerance of 10^-10 is:"<<endl;
	cout<<"                                                "<<setprecision(10)<<fd_newton(fV,V,maxit,tol,alpha)<<endl;

	return 0;
}
double fV(double V){
	double q=1.6022*pow(10.0,-19.0);
	double Kb=1.3806*pow(10.0,-23.0);
	double Voc=.8;
	double T=315.0;
	return (exp( (q*V)/(Kb*T) )*(1 + (q*V)/(Kb*T)) -exp( (q*Voc)/(Kb*T) ));
}
double dfV(double V){
	double q=1.6022*pow(10.0,-19.0);
	double Kb=1.3806*pow(10.0,-23.0);
	double T=315.0;
	return (exp( (q*V)/(Kb*T) )*(1 + (q*V)/(Kb*T))*(q/(Kb*T)) +exp( (q*V)/(Kb*T) )*(q/(Kb*T)));
}
