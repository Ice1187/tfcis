#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
	    
	        for(int n=a-i;n>0;n--){
	            cout<<" ";
	        }
	        
	        for(int k=2*i-1;k>0;k--){
	            cout<<"*";
	        }
	    cout << endl;
	}

return 0;
}