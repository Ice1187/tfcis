#include <iostream>
using namespace std;
long long Gcd(long long a, long long b){
	while (b!=0){
		a %= b;
		swap(a,b);
	}
	return a;
}

int main(){

	long long a,b;
	long long gcd;
	long long ans=1;
	while (cin >> a >> b){

		gcd = Gcd(a,b);
		a /= gcd;
		b /= gcd;
		ans = gcd * a * b;
		cout << ans << '\n';

	}

	return 0;
}
