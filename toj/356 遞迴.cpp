#include <iostream>
#include <cmath>
using namespace std;
int n;
int a[8200][8200];
int cnt=1;

void cpt(int x1, int y1, int x2, int y2){
	printf("%d %d %d %d\n",x1,y1,x2,y2);
	if (x1==x2 && y1==y2){
		a[x1][y1] = cnt++;
		return ;
	}
	int mx = (x1+x2)/2;
	int my = (y1+y2)/2;
	cpt(  x1,  y1,  mx,  my);
	cpt(mx+1,my+1,  x2,  y2);
	cpt(  x1,my+1,  mx,  y2);
	cpt(mx+1,  y1,  x2,  my);
	return ;
}

int main(){
	
	cin >> n;
	int k = (int)pow(2, n);
	cpt(1, 1, k, k);
	
	cout << '\n';
	for (int i=1; i<=k; i++){
		for (int j=1; j<=k; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	
	return 0;
}

