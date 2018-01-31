#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map<int, int> team;


int main(){

//	freopen("out.txt","w",stdout);

	int N,kase=1;
	while (cin >> N && N){
		cout << "Scenario #" << kase++ << '\n';
		for (int t=0; t<N; t++){
			int num,x;
			cin >> num;
			while (num--){
				cin >> x;
				team[x] = t;
			}
		}

		queue<int> q,qt[1000];
		string s;
		while (cin >> s){
			if (s[0]=='S')	break;

			else if (s[0]=='E'){
				int x;
				cin >> x;
				if (qt[team[x]].empty()) q.push(team[x]);
				qt[team[x]].push(x);
			}
			else if (s[0]=='D'){
				cout << qt[q.front()].front() << '\n';	
				qt[q.front()].pop();
				if (qt[q.front()].empty())	q.pop();
			}
		}
		cout << '\n';
	}

	return 0;
}
