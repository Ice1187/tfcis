#include <iostream>
#include <string>     //define str.compare
#include <stdlib.h>   //define atoi str => int
using namespace std;

int main(){

	string s;
	long long ans = 1;
	while (cin >> s){
		if (s.compare("%")==0){
			cout << ans%479001599 << '\n';
			ans = 1;
		}
		else {
			long long a = atoi(s.c_str());  //str.c_str()  string => char*
			ans = ans * a % 479001599;	
		}
	}
		

	return 0;
}

