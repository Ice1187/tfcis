#include <iostream>
#include <vector>
#define vy first
#define vt second
#define INF 2147483647
using namespace std;
int N,m;
int n[1005];
vector<pair<int, int>> v[1005];

bool bellmanFord(){
	bool changed = false;
	
	for (int i=0; i<N; i++){
		for (int j=0; j<v[i].size(); j++){
			int x = i, y = v[i][j].vy, t = v[i][j].vt;
			//Relax	
			if ( (n[y]==INF || (n[x] + t < n[y])) && n[x]!=INF ){
				n[y] = n[x] + t;
				changed = true;
			}
		}
	}
	return changed;
};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int c;
	cin >> c;
	while (c--){
		
		//input
		cin >> N >> m;
		for (int i=0; i<N; i++)	v[i].clear();	//init
		for (int i=0,x,y,t; i<m; i++){
			cin >> x >> y >> t;
			v[x].emplace_back(y,t);
		}
		
		//init
		for (int i=1; i<N; i++)	n[i] = INF;
		n[0] = 0;
		
		//bellman ford
		for (int T=0; T<N-1; T++){
			bellmanFord();
		}
		
		//nagetive cycle ? 
		bool nc;
		nc = bellmanFord();
		
		//output
		nc ? cout << "possible" : cout << "not possible";
		cout << '\n';
		
		//debug
//		for (int i=0; i<N; i++)
//			cout << n[i] << ' ';
//		cout << "\n\n";
	}
		
	return 0;
}

