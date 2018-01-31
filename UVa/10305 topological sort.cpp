#include <iostream>
#include <cstring>
#include <vector>
#define maxn 102
using namespace std;
int N;
int in[maxn];
int ans[maxn], ai;
int used[maxn];
vector<int> v[maxn];

void dfs(int n){
	
	if (used[n]) return;
	
	used[n] = true;
	ans[ai] = n;
	ai++;
	
	for (int i=0; i<v[n].size(); i++){
		int p = v[n][i];
		in[p]--;
		if (in[p]==0)
			dfs(p);
	}
	
	return;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int M;
	while (cin >> N >> M){
		
		if (!N && !M)
			break;
		
		ai=0;
		memset(in, 0, sizeof(in));
		memset(used, false, sizeof(used));
		memset(ans, 0, sizeof(ans));
		for (int i=0; i<N; i++)	v[i].clear();
			
		for (int i=0,a,b; i<M; i++)
			cin >> a >> b,
			v[a].push_back(b),
			in[b]++;
		
		for (int i=1; i<=N; i++){
			if (in[i]==0)
				dfs(i);
		}
		
		cout << ans[0];
		for (int i=1; i<ai; i++)
			cout << ' ' << ans[i];
	
		cout << '\n';
	}

	return 0;
}

