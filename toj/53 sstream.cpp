#include <iostream>
#include <sstream>
using namespace std;

int main(){

	string str;
	while (getline(cin, str)){
		
		stringstream ss(str);
		int n,ans = 0;
		
		while (ss >> n)
			ans = (ans + n) % 1000000007;
			
		cout << ans << '\n';
	}

	return 0;
}

