#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
/*	int a=-1,n=0,m=0,p=0;
	int i=30;
	
	i=(1+30)*i/2;
	
	for(int k=0;k<=30;k++){
		a++;
		n=a+n;  
		m=a*n;
		p=m+p;
}

cout<<(30+i+p)<<endl;
*/
int a,b,c=0;
for(int i=1;i<=30;i++)  {
	a=i;
	b=a*(1+a)*a/2;
	c=a+b+c+1;
}
cout<<c<<endl;
return 0;
}



