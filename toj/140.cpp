#include <iostream>
using namespace std;

int main(){

	int n;
	int a,b;
	int base26, base10;
	string s;
	cin >> n;
	while (n--){
		a = 0;
		b = 0;
		base26 = 1;
		base10 = 1;
		cin >> s;
		for (int i=2; i>=0; i--){
			a += (s[i]-'A')*base26;
			base26 *= 26;
		}
		for (int i=7; i>=4; i--){
			b += (s[i]-'0')*base10;
			base10 *= 10;
		}
		
		if (abs(a-b)<=100)
			cout << "nice";
		else 
			cout << "not nice";
		cout << '\n';
	}

	return 0;
}

