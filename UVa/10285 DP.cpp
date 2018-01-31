#include <iostream>
#include <cstring>
using namespace std;
int d[102][102];
int map[102][102];
int N,R,C;

int find(int x, int y){
	if (map[x][y] != -1)
		return map[x][y];
		
	int Max=0;
	if (x>0 && d[x-1][y] < d[x][y])
		Max = max(Max, find(x-1,y));
	if (y>0 && d[x][y-1] < d[x][y])
		Max = max(Max, find(x,y-1));
	if (x<R-1 && d[x+1][y] < d[x][y])
		Max = max(Max, find(x+1,y));
	if (y<C-1 && d[x][y+1] < d[x][y])
		Max = max(Max, find(x,y+1));	
	
	return map[x][y] = 1+Max;
}

int main(){

	string S;
	cin >> N;
	while (N--){
		cin >> S;
		cout << S << ": ";
		
		memset(d, 0, sizeof(d));
		memset(map, -1, sizeof(map));
		cin >> R >> C;
		for (int i=0; i<R; i++)
			for (int j=0; j<C; j++)
				cin >> d[i][j];
		
		int ans = -1;
		for (int i=0; i<R; i++)
			for (int j=0; j<C; j++)	
				ans = max(ans, find(i, j));
		
		cout << ans <<'\n';
	}
		
		
	return 0;
}

