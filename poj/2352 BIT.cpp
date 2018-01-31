#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 32005
using namespace std;
int N, n[maxn],cnt[maxn];

int lowbit(int x){
	return x & -x;
}

int sum(int x){
	int s=0;	
	while (x>0){
		s += n[x];
		x -= lowbit(x);
	}
	return s;
}

void add(int x, int d){
	while (x<maxn){
		n[x] += d;
		x += lowbit(x);
	}
}
		

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	while (cin >> N){
		
		memset(n, 0, sizeof(n));
		memset(cnt, 0, sizeof(cnt));
				
		for (int i=0; i<N; i++){
			//input
			cin >> x >> y;
			x++;				// x strat from 0
			
			cnt[sum(x)]++;
			add(x,1);
		}
		
		//output
		for (int i=0; i<N; i++)
			cout << cnt[i] << '\n';	
	}
	
	return 0;
}

