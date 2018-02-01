#include<iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> adj[102];
vector<int> AP;
int n;
int D[102];
int L[102];
int timestamp;

void adj_clear(){
	for (int i=0; i<102; i++)
		adj[i].clear();
}

void DFS(int v, int fa){
	D[v] = L[v] = timestamp++;
	int childcnt = 0;
	bool isAP = false;
	
	for (int w:adj[v]){
		if (w==fa)	continue;
		if (!D[w]){
			DFS(w,v);
			childcnt++;
			if (D[v]<=L[w])	isAP = true;
			L[v] = min(L[v], L[w]);
		}
		L[v] = min(L[v], D[w]);
	}
	
	if (v==fa && childcnt<2) isAP = false;
	if (isAP) AP.push_back(v);
	return;
}			

int main() {

	while (cin >> n && n){
		adj_clear();
		AP.clear();
		memset(D, 0, sizeof(D));
		memset(L, 0, sizeof(L));
		timestamp = 1;
		
		string str;
		int i,j;
		getline(cin, str);
		while (getline(cin, str)){
		
			stringstream ss(str);
			
			ss >> i;
			if (i==0)	break;
			while (ss >> j){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		DFS(j,j);
		cout << AP.size() << '\n';
	}
		
	
	return 0;
}

