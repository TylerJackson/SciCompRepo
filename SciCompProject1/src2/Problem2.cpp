/*
 * Problem2.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: Tyler Jackson
 *      This code solves problem 2 of the project involving the forward difference approximation.
 */
#include "Mat.h"
using namespace std;

int main(){
	//Problem 2
		Mat n(52,1);
		for(int i=0;i<52;i++){
			n(i)=i+1;
		}
		n.Write("n.txt");
		Mat h(52,1);
		for(int i=1;i<53;i++){
			h(i-1)=pow(2,-i);
		}
		cout<<"these are my h values: "<<endl;
		h.Write();
		double f_x=log(3);
		Mat df_x(52,1);
		for(int j=0;j<52;j++){
			df_x(j)=(log(3+h(j))-f_x)/h(j);
		}
		cout<<"This is diff est. of f'(3)"<<endl;
		df_x.Write();
		double f_p_x=1.0/3.0;
		Mat r(52,1);
		for(int i=0;i<52;i++){
			r(i)=(f_p_x-df_x(i))/f_p_x;
		}
		r.Abs();
		cout<<"these are my r values: "<<endl;
		r.Write();
		Mat q(52,1);
		for(int i=0;i<52;i++){
			q(i)=-log10(2*r(i));
		}
		cout<<"my q values"<<endl;
		q.Write("Q.txt");
		double f_p_p_x=-1.0/9.0;
		double c1=fabs(f_p_p_x/(2*f_p_x));
		double c2=fabs(f_x*h(51)/f_p_x);
		Mat R(52,1);
		for(int i=0;i<52;i++){
			R(i)=c1*h(i)+c2*(1/h(i));
		}
		cout<<"this is my R values:"<<endl;
		R.Write();
		Mat q_p(52,1);
		for(int i=0;i<52;i++){
			q_p(i)=-log10(2*R(i));
		}
		cout<<"these are my q_p vales: "<<endl;
		q_p.Write("Q_p.txt");
		return 0;
	}


