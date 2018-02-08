#include <iostream>
#include <cstring>
using namespace std;

int main(){

	long long a,b;
	char c;
	string s;
	while (cin >> s){
		cin >> c >> a >> c >> b >> c;
		if (s=="GCD"){
			while ((a%=b) && (b%=a)); 
			cout << a+b;
		}else if (s=="LCM"){
			long long A=a, B=b;
			while ((A%=B) && (B%=A));
			cout << a/(A+B)*b;	
		}else if (s=="ADD")
			cout << a+b;
		else if (s=="SUB")
			cout << a-b;
		else if (s=="MUL")
			cout << a*b;
		else if (s=="DIV")
			cout << a/b;
		cout << '\n';
	}
	return 0;
}

