#include <iostream>
#include <string.h>
#include <vector> 
using namespace std;
vector<pair<int, int>> v[10005];
int mx,mn;
bool used[10005];
bool DFS(int a,int c){
//	cout << "a=" << a << "\tc=" << c << '\n';
	used[a] = 1;
	if (c>mx)	return 0;
	if (c>=mn)return 1;
	
	for (int i=0; i<v[a].size(); i++){
		if (used[v[a][i].first] == 0)
			if (DFS(v[a][i].first, c+v[a][i].second))
				return 1;
	}
	return 0;	
};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	memset(used, 0, sizeof(used));
	//input
	cin >> N >> mn >> mx;
	for (int i=0,a,b,x; i<N-1; i++){
		cin >> a >> b >> x;
		v[a].emplace_back(b,x);
		v[b].emplace_back(a,x);
	}
	
	DFS(0, 0)? cout << "Eat Eat Eat":cout << "Go find other chickens";
	cout << '\n';	
	
	
	return 0;
}

