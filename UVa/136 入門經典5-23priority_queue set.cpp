#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long int LL;
priority_queue<LL, vector<LL>, greater<LL>> pq;
set<LL> s;
const int mul[3]={2,3,5};

int main(){
	
//	freopen("out.txt","w",stdout);

	pq.push(1);
	s.insert(1);
	for (int i=1; ; i++){
		LL top = pq.top();
		pq.pop();
		
		if (i==1500){
			cout << "The 1500'th ugly number is " << top << ".\n";
			break;
		}

		for (int k=0; k<3; k++){
			LL x = top * mul[k];
			if (s.count(x)==0) {
				s.insert(x);
				pq.push(x);
			}
		}

	}

	return 0;
}
