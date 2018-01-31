//­I¥]°ÝÃD http://www2.lssh.tp.edu.tw/~hlf/class-1/lang-c/DP.pdf
#include <iostream>
#include <string.h> 
using namespace std;
int w[100005],p[100005];
int d[100005];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int V,n;
	while (cin >> V){
		//init
		memset(d, 0, sizeof(d));
		
		//input
		cin >> n;
		for (int i=1; i<=n; i++)
			cin >> w[i] >> p[i];
		
		//compute
		for (int i=1; i<=n; i++){
			for (int j=w[i]; j<=V; j++){
				d[j] = max(d[j], d[j-w[i]] + p[i]); 
			}
		}
		
		//output
		cout << d[V] << '\n';
	}

	return 0;
}

