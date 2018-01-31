#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	if ('a' <= s[0] && s[0] <= 'z')
		s[0] -= ('a'-'A'); 
	
	cout << " Nice to see you, " << s << "!\n";

	return 0;
}

