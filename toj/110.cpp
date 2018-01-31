#include <iostream>
using namespace std;

int main()
{
int a,d;
cin>>a;
int b[a];
for(int i=0;i<a;i++){
	cin>>b[i];}
	
for(int c=0;c<a;c++){
	d=b[c];
	int e=0;
	for(int j=1;j>0;j++){

		if(j==d-2){
			for(int z=0;z<d*2-1;z++)
			{ cout<<"*"; }
			cout <<"\n";
			if(e==1) {j-=2;}
			continue;
			}
		if(j==d-1){
			cout<<" ";
			for(int l=0;l<2*d-3;l++){
			cout<<"*";	}
			cout <<"\n";
			j-=2; e++; continue;}

		for(int k=0;k<d-j;k++){
			cout << " ";}
		
		for(int p=0;p<2*j-1;p++){
			cout <<"*";
			}
		cout<<"\n" ;
		if(e==1) {j-=2;}
	}
}
return 0;
}

