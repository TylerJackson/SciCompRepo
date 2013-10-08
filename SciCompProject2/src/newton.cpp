
#include <math.h>
#include <iostream>
using namespace std;

double newton(double(*f)(const double),double(*df)(const double),double x,int maxit,double tol){
		cout<<endl;
		double h=0;
		for(int k=1;k<=maxit;k++){
			h=f(x)/df(x);
			x=x-h;
			cout<<"  iter "<<k<<": x is "<<x<<endl;
			cout<<"           |f(x)| is "<<fabs(f(x))<<endl;
			if(fabs(h)<tol)
				break;
		}
		cout<<"    error:  "<<fabs(f(x))<<endl;
		return x;
	}

