#include <iostream>
#include <cstring>
using namespace std;
int d[80];
int dp(int n){
	if (d[n]!=-1)
		return d[n];
		
	if (n>3)
		return d[n] = dp(n-2)+dp(n-3);
	else if (n==3)
		return d[n] = dp(n-2); 
	else 
		return 1;
};

int main(){

	memset(d, -1, sizeof(d));
	
	d[0] = 0;
	int n;
	while (cin >> n)
		cout << dp(n)+dp(n-1) << '\n';
	
	return 0;
}

