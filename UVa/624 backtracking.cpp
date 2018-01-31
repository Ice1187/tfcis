#include <iostream>
#include <string.h>
using namespace std;
int d[25][100005];
int Time[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,T;
	while (cin >> N >> T){
		//init
		memset(d, 0, sizeof(d));

		for (int i=1; i<=T; i++){
			//input
			cin >> Time[i];

			//compute
			for (int j=0; j<=N; j++){
				d[i][j] = d[i-1][j];
				if (j >= Time[i])
					d[i][j] = max(d[i][j], d[i-1][j-Time[i]] + Time[i]);
			};
		}

		//output
		int n=N;
		for (int i=T; i>0; i--){
			if (d[i][n] == d[i-1][n-Time[i]]+Time[i]){
				cout << Time[i] << ' ';
				n-=Time[i];
			}
		}
		cout << "sum:" << d[T][N] <<'\n';
	}

 	return 0;
}


