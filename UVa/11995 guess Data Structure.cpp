#include <bits/stdc++.h>
using namespace std;
int A[1005],B[1005];

void input(int n){
	for (int i=0; i<n; i++)
		cin >> A[i] >> B[i];
};

bool check_s(int n){
	stack<int> s;
	bool noinput = true;
	for (int i=0; i<n; i++){
		int a=A[i],b=B[i];
		
		if (a==1){
			noinput = false;
			s.push(b);
		}
		else {
			if(!s.empty() && b==s.top())
				s.pop();
			else
				return 0;
		};
	}
		
	return 1;
}
					
bool check_q(int n){
	queue<int> q;
	bool noinput = true;
	for (int i=0; i<n; i++){
		int a=A[i],b=B[i];
		
		if (a==1){
			noinput = false;
			q.push(b);
		}
		else {
			if(!q.empty() && b==q.front())
				q.pop();
			else
				return 0;
		};
	}
		
	return 1;
};

bool check_pq(int n){
	priority_queue<int> pq;
	bool noinput = true;
	for (int i=0; i<n; i++){
		int a=A[i],b=B[i];
		
		if (a==1){
			noinput = false;
			pq.push(b);
		}
		else {
			if(!pq.empty() && b==pq.top())
				pq.pop();
			else
				return 0;
		};
	}
		
	return 1;
}		

void solve(int n){
	int s,q,pq,r;
	s = check_s(n);
	q = check_q(n);
	pq = check_pq(n);
	
	r = s+q+pq;
	
	if (r>1)
		cout << "not sure";
	else if (r==0)
		cout << "impossible";
	else if (s)
		cout << "stack";
	else if (q)
		cout << "queue";
	else if (pq)
		cout << "priority queue";
	cout << '\n';
};
	

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("out.txt","w",stdout);
	
	int n;
	while (cin >> n && n){
		
		input(n);
		solve(n);

	}

	return 0;
}
