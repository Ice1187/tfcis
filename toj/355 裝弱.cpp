#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	cin >> n >> k;
	long long p[n];
	for (int i=0; i<n; i++)
		cin >>p[i];
 	sort(p,p+n);
	cout << p[n-2] << '\n';


 	return 0;
}

