#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
	int a,v=0;
	char b[100000],c;
	char d;
	cin >> a;
	
	for(int i=0;i<a;i++){
		cin >> b[i];
	}
	cin >>c;
	
	if(c==76){
	for(v;v<a;v++){
		if(b[v+1]==80){
			d=b[v+1];
			b[v+1]=b[v];
			b[v]=d;
			break ;}
	}}
	else{
	for(v;v<a;v++){
		if(b[v-1]==80){
			d=b[v-1];
			b[v-1]=b[v];
			b[v]=d;
			break ;}
	}}
	for (int k=0;k<a;k++){cout << b[k];
	}
	cout <<"\n"


;

return 0;
}

