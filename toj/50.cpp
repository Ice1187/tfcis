#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int key;
	string s;
	cin >> key;
	while (cin >> s){
		int num=0;
		int base=1;
		for (int i=6; i>=0; i--){
			if (s[i]=='X')
				num += base;
			base *= 2;
		}
//		cout << num << '\n';
		num ^= key;
		cout << (char)num;
	}
	
	return 0;
}

