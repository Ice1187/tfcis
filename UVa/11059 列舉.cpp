#include <iostream>
using namespace std;

int main(){

	int n;
	int l, r;
	int a[18];
	int kase = 1;
	long long ans, maxans;
//	bool separateline = 0;
	while (cin >> n && n){
//		if ( separateline )
//		separateline = 1;
			
		cout << "Case #" << kase++ << ": The maximum product is "; 
		
		for (int i=0; i<n; i++) 
			cin >> a[i];
		
		maxans = 0;
		for (l=0; l<n; l++){
			for (r=l; r<n; r++){
				ans = 1;
				for (int i=l; i<=r; i++)
//					cout << "A",
					ans *= a[i];
				maxans = max(maxans, ans);
			}
		}
		
		if (maxans == 0)
			cout << 0;
		else 
			cout << maxans;
		cout << ".\n";
		
		cout << '\n';
	}
		
			
	return 0;
}

