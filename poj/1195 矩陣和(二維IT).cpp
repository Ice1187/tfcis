#include <iostream>
#include <cstring>
#define maxn 1030
using namespace std;
int a[maxn][maxn];
int n;

void add(int x, int y, int k){
	while (x <= n){
		int y1 = y;
		while (y1 <= n){
			a[x][y1] += k;
			y1 += y1&-y1;
		}
		x += x&-x;
	}
};
		
int sum(int x, int y){
	int ans=0;
	while (x > 0){
		int y1 = y;
		while (y1 > 0){
			ans += a[x][y1];
			y1 -= y1&-y1;
		}
		x -= x&-x;
	}
	return ans;
}
	
int getsum(int x1, int y1, int x2, int y2){
	return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}

int main(){
	
	
	int tmp;
	int cmd;
	while (cin >> cmd){
		int x1,y1,x2,y2;
		switch (cmd){
			case 0:
				cin >> n;
				n++;
				memset(a, 0, sizeof(a));
				break;
			case 1:
				cin >> x1 >> y1 >> x2;
				x1++, y1++;
				add(x1, y1, x2);
				break;		
			case 2:
				cin >> x1 >> y1 >> x2 >> y2;
				x1++, y1++, x2++, y2++;
				cout << getsum(x1, y1, x2, y2) << '\n';		
				break;
			case 3:
				return 0;
			default:
				break;
		}
	}

	return 0;
}

