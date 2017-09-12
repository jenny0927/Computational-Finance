#include <iostream> 
#include <cmath>
#include<cstdio>
using namespace std; 

int df_and_r(double F0, double F1, double t0, double t1, double & df, double & r); 

int main(){
	double todayCashValue = 100;
	double futureCashValue = 200;
	double interestRate = 0.0;
	int todayTime = 1;
	int futureTime = 2; 
	double df = 0;
	int day = futureTime - todayTime;
	cout << "Today's cash value is $" << todayCashValue << endl;
	cout << "Future's cash value is $" << futureCashValue << endl;

	df_and_r(todayCashValue, futureCashValue, todayTime, futureTime, df, interestRate);
	cout << " with the day interest rate of " << interestRate << "% " << endl;
	return 0;
}

//D=1/(1+P)^n
int df_and_r(double F0, double F1, double t0, double t1, double & df, double & r)
{
	if (t1-t0 == 0.0) {
		df = 0;
		r = 0;
		return -1;
	}
	if ((F0 < 0.0) || (F1 < 0.0)) {
		df = 0;
		r = 0;
		return -2;
	}
	
	df = F0/F1;
	r = (1/df-1)/(t1-t0);
	cout << "Discount factor is " << df;
	
	return 0;
}
