#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N[10002];
int M[10002];
int d[10002];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//input
	int n,k;
	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> N[i];
	
	while (k--){
		//init
		memset(d, 0, sizeof(d));
		memset(M, 0, sizeof(M));
		
		//input
		for (int i=1; i<=n; i++) 
			cin >> M[i];
			
		//compute	
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				d[j] = max(d[j], d[j-1]);
				if (N[j]==M[i])
					d[j]++;
			}
		}

		//output		
			cout << d[n] << '\n';	
	}


	return 0;
}

