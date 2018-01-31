#include <iostream>
#include <string.h>
using namespace std;
struct {
	int a;
	int b;
	int l;
}e[10010];
int p[10010];

int main(){
	
	memset(p, -1, sizeof(p));
	
	int N,M,start,End;
	cin >> N >> M;
	for (int i=0; i<M; i++)
		cin >> e[i].a >> e[i].b >> e[i].l;
		
	cin >> start >> End;
	
	//bellman ford
	p[start] = 0;
	for (int j=0; j<N-1; j++){
		for (int i=0; i<M; i++){
			
			int a=e[i].a, b=e[i].b, l=e[i].l;
			if (p[a]!=-1){
				if (p[b]==-1 || p[b] > p[a]+l)
					p[b] = p[a] + l;
			}
			if (p[b]!=-1){
				if (p[a] == -1 || p[a] > p[b]+l)
					p[a] = p[b] + l;
			}
		}
	}
	
//	for (int i=1; i<=N; i++)
//		cout << p[i] << ' ';
	
	cout << p[End] << '\n';
	
	return 0;
}

