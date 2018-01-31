#include <iostream>
#define maxn 2000002
#define lowbit(x) (x&-x)
using namespace std;
int n;
int arr[maxn];
int bit[maxn]={0};

void add(int x, int c){
	while (x<=n){
		bit[x] += c;
		x += lowbit(x);
	}
}

int sum(int x){
	int ans=0;
	while (x>0){
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); 

	long long ans=0;
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i]; 			
		
		ans += i-sum(arr[i]);
		add(arr[i], 1);
	}
	
	cout << ans << '\n';

	return 0;
}

