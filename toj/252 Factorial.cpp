#include <iostream>
using namespace std;
long long p,a=9999999999999;
long long factorial(long long n){
	
	long long i=1,ans=1;
	while (i<=n){
		ans *= i;
		ans %= p;
		i++;
	}
	return ans;
		
};

int main(){
	
	long long n,m,ans;
	cin >> n >> m >> p;
	ans = factorial(n);
	ans += ((a%p)*m%p);
	ans %= p;
	cout << ans << '\n';

	return 0;
}

