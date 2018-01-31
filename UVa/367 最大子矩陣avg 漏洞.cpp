#include <iostream>
using namespace std;

int main(){
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	int N,M; 
	while (scanf("%d",&N) && 1){
		//init
		scanf("%d",&M); 
		double tmp,Max = -1;
		//input
		for (int i=1; i<=N; i++){
			for (int j=1; j<=M; j++){
				cout << "M=" << M << '\n';
				cout << i << '\t' << j << '\n';
				scanf("%llf",&tmp);
				if (tmp > Max)
					Max = tmp;
			}
		}
		printf("%.6llf\n",Max);
	}

	return 0;
}

