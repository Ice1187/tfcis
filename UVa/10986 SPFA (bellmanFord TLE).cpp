#include <iostream>
#include <vector>
#include <queue>
#define vy first
#define vw second
#define INF 2147483647
using namespace std;
int N,m,s,t;
int n[20002];
vector<pair<int, int>> v[20002];


void SPFA(){
	
	//declear
	queue<int> q;
	int parent[20002];		//加速 
	bool inq[20002];		//加速 
	//init
	for (int i=0; i<N; i++)	n[i] = INF;
	n[s] = 0;
	parent[s] = s;
	q.push(s);
	inq[s] = true;
	
	while (!q.empty()){
		int x = q.front();
		q.pop();
		inq[x] = false;
		
		if (inq[parent[x]])	continue;	//加速 
		
		for (int i=0; i<v[x].size(); i++){
			int y = v[x][i].vy, w = v[x][i].vw;
				
			if (n[x]!=INF && ( n[x]+w < n[y] )){ 
				n[y] = n[x]+w;
				parent[y] = x;
				
				if (!inq[y]){
					q.push(y);
					inq[y] = true;
				}
			}
		}
	}
	
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int T;
	cin >> T;
	for (int ti=1; ti<=T; ti++){
		
		cin >> N >> m >> s >> t;
		
		//init
		for (int i=0; i<N; i++)
			v[i].clear();
		
		for (int i=0,x,y,w; i<m; i++){
			cin >> x >> y >> w;
			// x to y
			v[x].emplace_back(y,w);
			// y to x
			v[y].emplace_back(x,w);
		}
		
		//shortPath
		SPFA(); 
		
		cout << "Case #" << ti << ": ";
		n[t]==INF ? cout << "unreachable" : cout << n[t];
		cout << '\n';
		
	}
		

	return 0;
}

