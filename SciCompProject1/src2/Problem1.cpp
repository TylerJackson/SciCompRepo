/* Problem 1
 * Tyler Jackson
 */
#include <iostream>
#include "Mat.h"

double factorial(int tempNum);
double nest(Mat&a, double x);
using namespace std;
int main(){
	Mat z=Linspace(-1.0,1.0,201);
	//calculate p_8(x) for x included in all z
	//coefficient vector for n=8 ->inputMat
	Mat inputMat(8,1);
	inputMat(0)=1;
	for(int i=1;i<8;i++){
		inputMat(i)=1.0/factorial(i);
	}
	Mat p_8 (201,1);
	for(int i=0;i<201;i++){
		p_8(i)=nest(inputMat,z(i));
	}
	//coefficient vector for n=12 ->inputMat2
	Mat inputMat2(12,1);
	inputMat2(0)=1;
	for(int i=1;i<12;i++){
		inputMat2(i)=1.0/factorial(i);
	}
	Mat p_12 (201,1);
	for(int i=0;i<201;i++){
		p_12(i)=nest(inputMat2,z(i));
	}
	//calculate etrue by taking e^x for x included in all z
	Mat etrue(201,1);
	for(int i=0;i<201;i++){
		etrue(i)=exp(z(i));
	}
	//compute err8 as absolute value of e^x-p_8(x)
	Mat err8(201,1);
	for(int i=0;i<201;i++){
		err8(i)=fabs(etrue(i)-p_8(i));
	}
	//compute err12 as absolute value of e^x-p_12(x)
	Mat err12(201,1);
	for(int i=0;i<201;i++){
		err12(i)=fabs(etrue(i)-p_12(i));
	}
	//approx for e^-13.2 using p_33(-13.2)
	//coefficient vector for n=33 ->inputMat3
	Mat inputMat3(33,1);
	inputMat3(0)=1;
	for(int i=1;i<33;i++){
		inputMat3(i)=1.0/factorial(i);
	}
	//the "true" value
	double eReal=exp(-13.2);
	cout<<"this is the true value for e^-13.2 using the exp function: "<<eReal<<endl;
	//this is the negative exponent
	double p_33Neg=nest(inputMat3,-13.2);
	cout<<"this is my predicted value for e^-13.2 using p_33(-13.2): "<<p_33Neg<<endl;
	//this is one over the positive exponent
	double p_33Pos =1.0/nest(inputMat3,13.2);
	cout<<"this is my predicted value for e^-13.2 using 1/p_33(13.2): "<<p_33Pos<<endl;
	z.Write("z.txt");
	p_8.Write("p8.txt");
	p_12.Write("p12.txt");
	err8.Write("err8.txt");
	err12.Write("err12.txt");
	etrue.Write("etrue.txt");
}

inline double nest(Mat&a, double x){
		int n=a.Rows();
		double p=a(n-1);
		for(int i=n-2;i>=0;i--){
			p=a(i)+p*x;
		}
		return p;
	}


inline double factorial(int tempNum) {
	double ans=tempNum;
	for(int i=tempNum-1;i>0;i--){
		ans=i*ans;
	}
	return ans;
}

