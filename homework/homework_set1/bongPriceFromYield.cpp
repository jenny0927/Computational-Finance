#include <iostream> 
#include <cmath>
#include<cstdio>
using namespace std; 

void price_from_yield(double F, double c, double y, int n, double & B);


int main(){
	double cashValue = 100;
	double coupon_decimal = 0.1;
	double interestPayment = cashValue * coupon_decimal;
	double yield = 8; 
	int n = 10;
	double bondPrice = 0.0;
	
	cout << "Today's cash value is $" << cashValue << endl;
	price_from_yield(cashValue,interestPayment,yield,n,bondPrice);
	return 0;
}

// 
void price_from_yield(double F, double c, double y, int n, double & B){
	double interestPayment = c/2;
	double yield_decimal = (y *0.01)/2 ;
	if(y==c) B = F;
	if(y==0) B = F + (n*c)/2;
	if(c==0) B = F / exp(1+y/2);
	for(int i =1; i < n ; i++){
		double currentValue =  interestPayment / pow((1+yield_decimal),i);
		B = B + currentValue;
		cout << i << "th period: " << currentValue << endl;
	}
	cout << n << "th period: " << (F + interestPayment) / pow((1+yield_decimal),n) << endl;
	B = B + (F + interestPayment) / pow((1+yield_decimal),n);
	cout << "bond value is " << B << endl;
	cout << "bond price is " << B/n;
} 

