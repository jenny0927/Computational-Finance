#include <iostream> 
#include <cmath>
#include<cstdio>
using namespace std; 

int yield_from_price(double F, double c, int n, double B_market, double tol, int max_iter, double & y);
double price_from_yield(double F, double c, double y, int n, double & B);

int main(){
	double todayCashValue = 100;
	double coupon_decimal = 0.10;
	double interestPayment = todayCashValue * coupon_decimal;
	double yield =8 ; 
 	int n = 10;
 	
 	double B_market = 100;
	double bondPrice;
	double tol = 0.001;
	int max_iter =10;
	
	//cout << "price_from_yield " << price_from_yield(todayCashValue, interestPayment, yield, n, bondPrice ) << endl;
	if (yield_from_price(todayCashValue, interestPayment, n, B_market, tol, max_iter, yield) ==0)
	cout << "the yield is " << yield<< endl;
	else if(yield_from_price(todayCashValue, interestPayment, n, B_market, tol, max_iter, yield) == 1)
	
	cout << "couldn't find the answer in " <<max_iter << " times loops," <<endl;

	return 0;
}

double price_from_yield(double F, double c, double y, int n, double & B){
	double interestPaymentPerPeriod = c/2;
	double yield_decimal = (y *0.01)/2  ;
	for(int i =1; i < n ; i++){
		double currentValue =  interestPaymentPerPeriod / pow((1+yield_decimal),i);
		B = B + currentValue;
//		cout << B << endl;
	}	
	B = B + (F + interestPaymentPerPeriod) / pow((1+yield_decimal),n);
	return B;
}

int yield_from_price(double F, double c, int n, double B_market, double tol, int max_iter, double & y){
	
	double interestPaymentPerPeriod = c/2;
	double yield_decimal = (y *0.01)/2  ;
	double y_low = 0.0;
	double y_high = 100.0;
	double B_y_low, B_y_high, B;
	
	B_y_low = price_from_yield(F, c, y_low, n, B_y_low);
	//cout << "B_y_low " << B_y_low << endl;
	if(abs(B_y_low - B_market) <= tol) {
		y = y_low;
		return 0; 
	} 
	if(B_y_low < B_market) {
		y = 0; 
		return 1;
	}
	
	B_y_high = price_from_yield(F, c, 100, n, B_y_high);
//	cout << "B_y_high " << B_y_high << endl;
	
	if(abs(B_y_high - B_market) <= tol) {
		y = y_high;
		return 0; 
	} 
	if(B_y_high > B_market){
		y= 0; 
		return 1;
	}

	for(int i = 0; i< max_iter; ++i){
		cout << "interation " << i <<"th------------------------------------------------"<< endl;
		cout << "y_low: " << y_low << endl;
		cout << "y_high: " << y_high << endl	
	//	cout << "B_market "<<B_market << endl;
		y = (y_high + y_low)/2;
		cout << "yield: " << y << endl;
		B = price_from_yield(F, c, y, n, B);	

		cout << "B " << B << endl;
		if(abs(B - B_market) <= tol) 	return 0; 
		cout << "tolerance: " << B-B_market << endl;
		if(B > B_market)  y_low = y;

		if(B < B_market)  y_high = y;
		if (y_high - y_low <= tol) return 0;
	}
	
	y=0;
	return 1;
}
