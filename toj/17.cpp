#include <iostream>
using namespace std;

int main(){
	int a,j=0;
	cin>>a;
	for(int i=1; i>0; i++){
	int o=0;
		for(int n=a-i ;n>0 ;n--)
			cout <<" ";
		for(int m=1 ; m>0 ;m++){
			char ch=m+64;
			cout << ch;
			if(m==i || o>0){
				o++; 
				m-=2;
			}
		}
	    cout<<"\n";
	 	if(i==a ||  j>0){
			j++;
			i-=2;
		}
	}
	return 0;
}
