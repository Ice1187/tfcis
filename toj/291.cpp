#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
string a;
char x='A';
cin>>a;

for(int i=0;i<51;){

if(x=='A'){

	if(a[i]=='0')
	{i++; x='B';}

	else
	{a[i]='0'; i+=2; x='D';}
}
else if(x=='B'){

	if(a[i]=='0')
	{a[i]='0'; i--; x='D';}
	
	else
	{break;}
}
else if(x=='C'){

	if(a[i]=='0')
	{a[i]='1'; i+=2; x='E';}
	
	else
	{a[i]='0'; i-=2; x='A';}
}
else if(x=='D'){

	if(a[i]=='0')
	{a[i]='1'; i++; x='C';}
	
	else
	{i++; x='E';}
}
else if(x=='E'){

	if(a[i]=='0')
	{i++; x='A';}
	
	else
	{i--; x='C';}
}
}
cout<<a;
	return 0;
}
