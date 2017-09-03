#include <iostream> 
using namespace std; 

double future_value(double F0, double t0, double t1, double r);

int main(){
	fuure_value(100,1,180,5);
}


double future_value(double F0, double t0, double t1, double r)
{
double r_decimal = 0.01*r;
double F1 = F0*exp(r_decimal*(t1-t0));
return F1;
}
