#include <iostream> 
#include <cmath>
#include<cstdio>
using namespace std; 

int yield_from_price(double F, double c, int n, double B_market, double tol, int max_iter, double & y);
double price_from_yield(double F, double c, double y, int n, double & B);

int main(){
	double todayCashValue = 100;
	double coupon = 1;
	double yield = 0; 
 	int n = 10;
 	double B_market = 100;
	double bondPrice = 0.0;
	double tol = 0.1;
	int max_iter =10;

	cout <<	yield_from_price(todayCashValue, coupon, n, B_market, tol, max_iter, yield);

	return 0;
}

double price_from_yield(double F, double c, double y, int n, double & B){
	double interestPayment = F/n/2;
	if(y==c) B = F;
	if(y==0) B = F + (n*c)/2;
	if(c==0) B = F / exp(1+y/2);
	for(int i =1; i < n ; i++){
		double currentValue =  interestPayment / pow((1+y*0.01),i);
		B = B + currentValue;
	}	
	B = B + (F + interestPayment) / pow((1+y*0.01),n);
	return B;
}

int yield_from_price(double F, double c, int n, double B_market, double tol, int max_iter, double & y){
	double y_low = 0.0;
	double y_high = 100.0;
	double B_y_low, B_y_high, B;
	
	B_y_low = price_from_yield(F, c, y_low, n, B_y_low);
	cout << "B_y_low " << B_y_low << endl;
	if(abs(B_y_low - B_market) <= tol) {
		y = y_low;
		return 0; 
	} 
	if(B_y_low < B_market) {
		y= 0; 
		return 1;
	}
	
	B_y_high = price_from_yield(F, c, y_high, n, B_y_high);
	cout << "B_y_high " << B_y_high << endl;
	if(abs(B_y_high - B_market) > tol) {
		y = y_high;
		return 0; 
	} 
	if(B_y_high > B_market){
		y= 0; 
		return 1;
	}

	for(int i = 0; i< max_iter; ++i){
		y = (y_high + y_low)/2;
		B = price_from_yield(F, c, y, n, B);	

		cout << "B " << B << endl;
		if(abs(B - B_market) <= tol) 	return 0; 
		if(B > B_market)  y_low = y;
		if(B < B_market)  y_high = y;
		if (y_high - y_low <= tol) return 0;
	}
	y = 0; 
	return 0;
}
