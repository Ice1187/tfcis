#include <iostream>
#include <sstream>
using namespace std;

int main(){
	
	string S;
	long long ans;
	while (getline(cin, S)){
		 
		stringstream ss(S);
		string s;
		ans = 0;
		 
		while (ss >> s){
			bool isslash = false;
			
		 	for (int i=0; i<s.size(); i++)
		 		if (s[i] == '/'){
		 			isslash = true;
					break;
				}
		 	
		 	if (isslash)
			 	continue;	
		 	else {
		 		int k = atoi(s.c_str());
		 		ans += k;
		 		ans %= 1000000007;
		 	}
		}
		
		cout << ans%1000000007 << '\n';
	}
		 	

	return 0;
}

