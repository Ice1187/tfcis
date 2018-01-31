#include <iostream>
#include <string.h>
using namespace std;
int n[105][105];

int main(){
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N,max;
	cin >> N >> M;
	
	//init
	Max = -1;	
	memset(n, 0, sizeof(n));
	
	//input
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++)
			cin >> n[i][j];
	}
		
	//set matrix (top left sum)
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			n[i][j] += n[i-1][j];
			n[i][j] += n[i][j-1];
			n[i][j] -= n[i-1][j-1];
		}
	}
	
	//compute matrix (every matrix sum)
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			//each matrix cmp
			int t=-1, x;
			for (int I=i-1; I>=0; I--){
				for (int J=j-1; J>=0; J--){
					x = n[i][j] - n[i][J] - n[I][j]	+ n[I][J];
					if (x>t) //maximize ³Ì¤j¤Æ 
						t = x;
				}
			}

		//cmp max	
		if (t>Max)
			Max = t;	
		}
	}
	
	cout << Max << '\n';

}
