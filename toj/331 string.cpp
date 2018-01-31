#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	string a,b;
	long long ca=0, cb=0;
	cin >> a >> b;

	for (int i=0; i<a.size(); i++)
		if (a[i]!='0')
			ca++;
	for (int i=0; i<b.size(); i++)
		if (b[i]!='0')
			cb++;
			
	cout << ca*cb << '\n';
	
		


	return 0;
}

