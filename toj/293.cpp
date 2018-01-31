#include <iostream>
using namespace std;

long long gcd(long long x, long long y){
	if (x < y)	swap(x, y);
	while ( y != 0 ){
		x %= y;
		swap(x, y);
	}
	return x;
}	

int main() {
	
	ios::sync_with_stdio(false);
    cin.tie(0);
    
	long long a,b,x,y,n,g;
	
	while ( cin >> a >> b >> x >> y ){
		 
		g = gcd(x, y);
		x /= g;
		y /= g;
		
		n = min(a/x, b/y);
		
		cout << x*n << ' ' << y*n;
		cout << '\n';
		
	}

	return 0;
}
