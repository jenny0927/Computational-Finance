#include <iostream> 
#include <cmath>
#include<cstdio>
using namespace std; 

double future_value(double F0, double t0, double t1, double r);

int main(){
	double cashValue = 100;
	double interestRate = 5.0;
	int todayTime = 1;
	int futureTime = 2; 
	int day = futureTime - todayTime;
	cout << "Today's cash value is $" << cashValue << endl;
	cout << day << " day(s) later, ";
	cout << "the future value is $"<< future_value(cashValue,todayTime,futureTime,interestRate);
	return 0;
}


double future_value(double F0, double t0, double t1, double r)
{
	double r_decimal = 0.01*r;
	double F1 = F0*exp(r_decimal*(t1-t0));
	return F1;
}
