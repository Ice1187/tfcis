#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
//vector<unsigned int> v;

int main(){

	while (cin >> N){
// xor O(N)
		unsigned int a,ans=0;
		for (int i=0; i<N; i++)
			cin >> a,
			ans ^= a;
			
		cout << ans << '\n';
	}
		
// O(N log N)
//		unsigned int ans = 0;
//		
//		v.clear();
//		
//		for (unsigned int i=0,a; i<N; i++)
//			cin >> a,
//			v.push_back(a);
//
//		sort(v.begin(), v.end());
//		
//		for (int i=0; i<N;){
//			unsigned int k=(upper_bound(v.begin(), v.end(), v[i])
//				- lower_bound(v.begin(), v.end(), v[i]));
//			if (k%2==1){
//				ans = v[i];
//				break;
//			}
//			i += k;
//		}	
//		cout << ans << '\n';
//	}

	return 0;
}
