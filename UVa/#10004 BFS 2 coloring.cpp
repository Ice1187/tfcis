/*
	48
	used[v[q.front()][i]] = -used[q.front()]
							必須使用-used[q.front()]
							不能使用-u 變換 
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[202];
queue<int> q;

int main(){
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int used[202];
	int n,m;
	bool nok;
	
	while (cin >> n && n!=0){
		cin >> m;
		//init
		while (!q.empty())
			q.pop();
		for (int i=0; i<n; i++)
			v[i].clear();
		nok = false;
		memset(used, 0 , sizeof(used));
		
		//input
		for (int i=0,a,b; i<m; i++){
			cin >> a >> b;
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		
		//compute
		used[0] = 1;
		q.emplace(0);
		while (!q.empty()){
			
			//coloring
			for (int i=0; i<v[q.front()].size(); i++){
				// ! used 
				if (used[v[q.front()][i]]==0){
				    q.emplace(v[q.front()][i]);
				    used[v[q.front()][i]] = -used[q.front()];
	   			}     
				// used	Wa
				else if (used[v[q.front()][i]]==used[q.front()]){
					nok = true;
					break;
				}
			}
			
			//nok?
			if (nok)
				break;
			//pop
			q.pop();
		}
		
		//output
		nok ? cout << "NOT BICOLORABLE.": cout << "BICOLORABLE.";
		
		//next
		cout << '\n';
	}
		
	return 0;
}

