	#include <iostream>
	using namespace std;
	int N[105][105];
	int N1[105],N2[105];
	int max(int a,int b,int c){
		int Max;
		a>b? Max=a:Max=b;
		c<Max? :Max=c;
		return Max;
	}

	int main(){
//		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
		int n1,n2,count=0;
		while (cin >> n1 >> n2 && n1!=0 && n2!=0){
			//init
			count++;
			for (int i=0; i<n1; i++)
				N[i][0] = 0;
			for (int i=0; i<n2; i++)
				N[0][i] = 0;

			//input
			for (int i=1; i<=n1; i++)
				cin >> N1[i];
		 	for (int i=1; i<=n2; i++)
				cin >> N2[i];

			//compute
				for (int i=1; i<=n1; i++){
					for (int j=1; j<=n2; j++){
						if (N1[i]==N2[j])
							N[i][j] = N[i-1][j-1]+1;
						else
							N[i][j] = max(N[i-1][j],N[i-1][j-1],N[i][j-1]);
					}
				}

			//output
	//		for (int i=0; i<=n1; i++)
	//			for (int j=0; j<=n2; j++)
			printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",count,N[n1][n2]);

		}
		return 0;
	}


