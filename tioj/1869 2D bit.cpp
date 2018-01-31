#include <iostream>
#include <cstring>
#define maxn 1030
#define lowbit(x) (x&-x)
using namespace std;
int n;
int bit[maxn][maxn];

void add(int x, int y, int c){
	for (; x<=n; x+=lowbit(x))
		for (int j=y; j<=n; j+=lowbit(j))	
			bit[x][j]+=c;
}

long long sum(int x, int y){
	long long ans=0;
	for (; x>0; x-=lowbit(x)){
		for (int j=y; j>0; j-=lowbit(j)){
			ans += bit[x][j];
		}
	}
	return ans;
}

long long query_sum(int x1, int y1, int x2, int y2){
	return sum(x2, y2)-sum(x2, y1-1)-sum(x1-1, y2)+sum(x1-1, y1-1);
}
		
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	memset(bit, 0, sizeof(bit));
	int q,x1,y1,x2,y2;

	cin >> n;
	n++;
	while (cin >> q){
		if (q==1){
			cin >> x1 >> y1 >> x2;
			x1++, y1++;
			add(x1, y1, x2);
		}
		else if (q==2){
			cin >> x1 >> y1 >> x2 >> y2;
			x1++, y1++, x2++, y2++;
			cout << query_sum(x1, y1, x2, y2) << '\n';
		}
	}

	return 0;
}

