//AC UVA 11258 by.tangerine1202 
#include <iostream>
#include <cstring>
using namespace std;
string a;
int size;
long long dp[502][502];

long long sum(int L, int R){
	if (dp[L][R] != -1)
		return dp[L][R];
		
	long long ret=0;
	for (int t=1, r=R; L<=r; r--, t*=10){
		ret += (long long)(a[r]-'0')*t;
		if (ret > 2147483647)
			return dp[L][R] = -10000000000000000;
		}
	return dp[L][R] = ret;
}

long long sol(int k){
	if (dp[k][size-1] != -1)
		return dp[k][size-1];
	if (k==size)
		return 0;
	
	long long ret = 0, cnt=0, calc;
	for (; cnt<10 && k+cnt<size; cnt++){
		ret = max(ret, sum(k,k+cnt)+sol(k+cnt+1));
	}
	
	return dp[k][size-1] = ret;
}

int main() {
	
	int times;
	cin >> times;
	while (times--){
		memset(dp, -1, sizeof(dp));
		cin >> a;
		size = a.size();
		cout << sol(0) << '\n';
	}
	
	return 0;
}
