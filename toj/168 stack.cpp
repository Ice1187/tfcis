#include <iostream>
#include <stack>
using namespace std;
stack<int> s;

inline void clear(){
	while (!s.empty())
		s.pop();
	return;
}

int main(){

	int n,k;
	while (cin >> n && n){
		clear();
		for (int i=0; i<n; i++){
			cin >> k;
			while (!s.empty() && k>=s.top())
				s.pop();
			s.push(k);
		}
		cout << s.size() << '\n';
	
	}
			
	return 0;
}

