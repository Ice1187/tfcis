#include <iostream>
#include <cstring>
using namespace std;
int N,M;
int map[1002][1002];

int main(){

//	ios::sync_with_stdio(false);
//	cin.tie(0); 

	while (~scanf("%d %d",&N,&M) && 1){
		//init
		memset(map, 0, sizeof(map));
		
		//input
		for (int i=1; i<=N; i++){
			for (int j=1; j<=M; j++){
				cin >> map[i][j];
			}
		}
		
		//set map
		for (int i=1; i<=N; i++){
			for (int j=1; j<=M; j++){
				map[i][j] += map[i][j-1];
				map[i][j] += map[i-1][j];
				map[i][j] -= map[i-1][j-1];
			}
		}
		
		//compare
		double Max = -1;
		for (int i=1; i<=N; i++){
			for (int j=1; j<=M; j++){
				double tmp;
				for (int k=0; k<=i-1; k++){
					for (int l=0; l<=j-1; l++){
						tmp = map[i][j] - map[i][l] - map[k][j] + map[k][l];
						tmp /= ((i-k)*(j-l));
//						printf("i=%d j=%d k=%d l=%d tmp=%llf\n",i,j,k,l,tmp);
						if (tmp > Max){
//							printf("i=%d j=%d k=%d l=%d max=%llf\n",i,j,k,l,tmp);
							Max = tmp;
						}
					}
				}
			}
		}
		
		printf("%.6llf\n",Max);
	
	}

	return 0;
}

