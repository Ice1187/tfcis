#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
	int a,k=0;
	int b[1000];
	cin >> a;
	for(int i=0 ; i<a ;i++)
	{cin >> b[i];}
	
	for(int d=0 ; d<a ; d++){
	k=b[d];
		for(int e=1; e<=k ; e++){
		int v=0;
		int m=0;
		int n=2*e-1;
		
			for(int f=e ; f<k ;f++){
				cout << " ";
			}
			
			for(int g=k ; g>(-k+1) ;g--){
				
				char ch=g+v+64;
				cout << ch;
				m++;
				if(m==e||(v!=0))
					v=v+2;
				if(m==n)
					break;

			}
		cout <<"\n";
		}
		
		for(int l=k-1 ; l>0 ;l--)	{
		int j=0;
		int p=0;
		int q=l*2-1;
		
			for(int h=0;h<k-l;h++){
				cout << " ";}

			for(int v=k;v>(-l+1);v--){
		
				char chi=v+p+64;
				cout << chi;
				j++;
				if(j==l||p!=0)
					p=p+2;
				if(j==q) break;
			}
		cout << endl;
		}
	}
return 0;
}

