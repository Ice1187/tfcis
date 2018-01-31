#include <iostream>
#include <time.h>
using namespace std;

long long int pow(long long int a,long long int b,int c){
	if (b == 0) 
		return 1; 
	if (b == 1)
		return (a%c);
	long long half = pow(a,b/2,c);
	
	if (b%2 == 1)	
		return ((half*half)%c*a)%c;
	else 
		return ((half*half)%c);
};

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a,b,c,r;
	cin >> a >> b >> c; 
	r = pow(a,b,c);
	cout << r << '\n';
	
	return 0;
}


