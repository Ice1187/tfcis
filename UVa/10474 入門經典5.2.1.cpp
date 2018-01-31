#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=10000;
int main(){
	int N,Q,kase=1,a[maxn],x;
	while (scanf("%d%d",&N,&Q) == 2 && N){
		printf("CASE# %d:\n",kase++);

		for (int i=0; i<N; i++)	
			cin >> a[i];
		
		sort(a, a+N);
		
		while (Q--){
			cin >> x;
			int p = lower_bound(a,a+N,x) - a;
			if (a[p]==x)	
				printf("%d found at %d\n",x,p+1);
			else 
				printf("%d not found\n",x);
		}
	}
}
