#include <iostream>
#include <sstream>
#include <stdlib.h>		//define strtol(char* str, endpointer, base)
						//http://www.cplusplus.com/reference/cstdlib/strtol/
using namespace std;

int main(){

	string S;
	bool isslash;
	long long ans;
	while (getline(cin, S)){
		
		ans = 0;
		stringstream ss(S);
		string s;
		
		while (ss >> s){
			
			isslash = false;
			for (int i=0; i<s.size(); i++)
				if (s[i] == '/'){
					isslash = true;
					break;
				}
				
			if (!isslash){ 
				ans += atoi(s.c_str());
				ans %= 1000000007;
			}
			else {
				char *ptr;
				long long a,b;
				a = strtol(s.c_str(), &ptr, 10);
				b = strtol(++ptr, NULL, 10);
				if (a%b==0){
					ans += a/b;
					ans %= 1000000007;
				}
			}
		}
		cout << ans%1000000007 << '\n';
	}
				

	return 0;
}

