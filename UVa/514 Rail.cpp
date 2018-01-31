#include <iostream>
#include <stack>
using namespace std;
int N;
stack<int> b,t,a;

void move(stack<int> &x, stack<int> &y, int check){
	while (!x.empty() && x.top() > check)
		y.push(x.top()),
		x.pop();
};

void solve(int x){
	if (t.empty()){
		t.push(x);
		return;
	}
	if (x < t.top())
		move(t, a, x);
	t.push(x);
};
		

int main(){
	
	while (cin >> N){
		
		if (N==0)
			break;
		
		int x0;
		while (cin >> x0){
			
			if (x0==0)
				break;
			
			b.push(x0); 
			for (int i=1,x; i<N; i++){
				cin >> x;
				b.push(x);
			}
			
			while (!b.empty()){
				int now = b.top();	
				b.pop();
				solve(now);
			}
			move(t, a, -1);
			
			bool ans=true;
			int count=1;
			while (!a.empty()){
				if (a.top()!=count){
					ans = false;
				}
				count++;
				a.pop();
			}
			ans ? cout << "Yes" : cout << "No";
			cout << '\n';
		}
		cout << '\n';
	}
		
		
	return 0;
}
