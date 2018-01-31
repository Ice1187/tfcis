#include <iostream>
#include <cmath>
using namespace std;

double equation1(double a,double b,double c,double d){
	return  ((b*c)/(6*a*a))
			-((b*b*b)/(27*a*a*a))
			-(d/(2*a));
}

double equation2(double e,double a,double b,double c){
	double n = (c/(3*a))-((b*b)/(9*a*a));
	return sqrt((e*e)+(n*n*n));
}
	
int main()
{
	int n;
	cin >> n;
	while(n--){
		double a,b,c,d,e1,e2,x;
		cin >> a >> b >> c >> d;
		e1 = equation1(a,b,c,d);
		e2 = equation2(e1,a,b,c);
		x = ((-1*b)/(3*a))
			+cbrt(e1+e2)
			+cbrt(e1-e2);
		printf("%.3lf\n",x);
	}

 	return 0;
}

