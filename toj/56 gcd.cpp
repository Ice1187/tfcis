#include <iostream>
using namespace std;

long long solve_h(long long n, long long m){
	
    //max n, min m
    if (m>n)    swap(n, m);
    
    //gcd
    while (m!=0) {
        n = n % m;
        swap(n, m);
    }
    
    //return
    return n;
};

long long solve_wdf(long long n, long long m){
	
	long long H = solve_h(n, m);
	n /= H;
	
	return n*m;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //¦Ï¦Ï n , ©¼±o¼ï m
    long long n,m;
    long long h;
    while (cin >> n >> m){
        
        //solve first h
        h = solve_h(n, m);
        
        //solve second h
        n = n+m;
        h = solve_h(n, h);
        
        cout << h << '\n';
    }
    
    return 0;
}
