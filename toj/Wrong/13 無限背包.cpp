#include <iostream>
#include <string.h>
using namespace std;
int cost[105];
int weight[105];
int c[106][100005];

//要從0~n  不是n~0 
int pack(int n, int w){
	if (n < 0) return 0;
	if (w >= weight[n])
		return c[n][w] = max( pack(n-1,w), 
						      pack(n,w-weight[n]) + cost[n] );
	return c[n][w] = pack(n-1,w);
};
	

int main(){
	int V,N;
	while (cin >> V){
		//init
		memset(c, 0, sizeof(c));
		
		//input
		cin >> N;
		for (int i=1; i<=N; i++)
			cin >> weight[i] >> cost[i];	
		
		//compute
		pack(N,V); 
		
		//debug 
//		for (int i=0; i<=N; i++){
//			for (int j=0; j<=w; j++){
//				cout << c[i][j] << ' ';
//			}
//			cout << '\n';
//		}
		
		//output
		cout << c[N][V] << '\n';
	}

	return 0;
}

