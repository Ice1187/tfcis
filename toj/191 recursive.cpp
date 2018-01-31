#include <iostream>
#include <cstring>
using namespace std;
int n,m,sx,sy,tx,ty;
int map[15][15];

void solve(int i, int j){
	
	if (i==sx && j==sy)
		return;
	
	if (i>sx)
		solve(i-1, j);
	if (j>sy)
		solve(i, j-1);
	

	int a=0;
	if (i>sx && j>sy)
		a += map[i-1][j-1];
	if (i>sx)
		a += map[i-1][j];
	if (j>sy)
		a += map[i][j-1];
		
	map[i][j] = a;
	
	return;
};	

int main(){
	
	while (cin >> n >> m){
		
		memset(map, 0, sizeof(map));
		cin >> sx >> sy;
		cin >> tx >> ty;
		
		map[sx][sy] = 1;
		solve(tx, ty);
		
		cout << map[tx][ty] << '\n';

	}
	
	return 0;
}

