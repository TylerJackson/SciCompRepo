#include <math.h>
#include <iostream>
using namespace std;
double dplusf(double(*f)(const double),double x,double alpha);

double fd_newton (double(*f)(const double),
		double x,int maxit,double tol,double alpha){
	cout<<endl;
	double h=0;
	for(int k=1;k<=maxit;k++){
		h=f(x)/dplusf(f,x,alpha);
		x=x-h;
		cout<<"  iter "<<k<<": x is "<<x<<endl;
		cout<<"           |f(x)| is "<<fabs(f(x))<<endl;
		if(fabs(h)<tol)
			break;
	}
	cout<<"    error:  "<<fabs(f(x))<<endl;
	return x;
}

double dplusf(double(*f)(const double),double x,double alpha){
	return ((f(x+alpha)-f(x))/alpha);
}



