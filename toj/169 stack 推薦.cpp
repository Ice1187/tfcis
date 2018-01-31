#include <iostream>
#include <stack>
#define c first
#define x second
using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n){
		int tx;
		stack<pair<int, int>> s;
		pair<int, int> tmp;
		
		for (int i=0; i<n; i++){
			cin >> tx;
			tmp = make_pair(i, tx);
			if (i==0){s.push(tmp); cout << 0; continue;} 
			
			while ((!s.empty()) && tmp.x > s.top().x)	s.pop();
			if (s.empty())	cout << ' ' << tmp.c;
			else 			cout << ' ' << tmp.c - s.top().c-1;
			s.push(tmp);
		}
		cout << '\n';
	}
	
	return 0;
}

