#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{

	double a,b,c;
	char x;

	cin >> a >> x >> b;

	if(x==43){

		c=a + b;

	cout<<fixed<<setprecision(4)<<a<<" "<<x<<" "<<b<<" = "<<c<<endl;
	}

	else if(x==45)
{			c=a - b;

	cout<<fixed<<setprecision(4)<<a<<" "<<x<<" "<<b<<" = "<<c<<endl;
}

	else if(x==42)
{			c=a * b;

	cout<<fixed<<setprecision(4)<<a<<" "<<x<<" "<<b<<" = "<<c<<endl;
}

	else if(x==47&&b==0)
{	printf("ERROR\n");
}
	else
{			c=a / b;

	cout<<fixed<<setprecision(4)<<a<<" "<<x<<" "<<b<<" = "<<c<<endl;
}
return 0;
}

