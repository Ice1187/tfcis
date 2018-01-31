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
	cin >> N;
	
	//init
	max = -1e9;	
	memset(n, 0, sizeof(n));
	
	//input
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++)
			cin >> n[i][j];
	}
		
	//set matrix (top left sum)
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			n[i][j] += n[i-1][j];
			n[i][j] += n[i][j-1];
			n[i][j] -= n[i-1][j-1];
		}
	}

	//compute matrix (every matrix sum)
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			//each matrix cmp
			int t=-1e9, x;
			for (int I=i-1; I>=0; I--){
				for (int J=j-1; J>=0; J--){
					x = n[i][j] - n[i][J] - n[I][j]	+ n[I][J];
					if (x>t) //maximize ³Ì¤j¤Æ 
						t = x;
				}
			}

		//cmp max	
		if (t>max)
			max = t;	
		}
	}
			
	//output
	cout << max << '\n';
	
	return 0;
}

//5     int k[105][105];
//20	memset(k, 0, sizeof(k));
//47    k[i][j] = t;
//51	cout << "t=" << t << ' ';
//56	cout << '\n';

//	for (int i=1; i<=N; i++){
//		for (int j=1; j<=N; j++)
//			cout << k[i][j] << ' ';
//		cout << '\n';
//	}
