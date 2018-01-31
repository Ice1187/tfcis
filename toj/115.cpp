#include <iostream>
using namespace std;

int main()
{
	int a;
	int c[10000];
	string b[10000];
	cin>>a;
	for(int i=0 ; i<a ; i++)
		{cin >> b[i] >> c[i] ;}
	for(int v=1 ; v<=10 ;v++){
		for(int k=0 ; k<=11; k++){
			if(c[k]==v)
				{cout << b[k] <<endl;break;}
			else if(k==11)
				{cout << "EMPTY"<<endl;}	}	}
return 0;
}
