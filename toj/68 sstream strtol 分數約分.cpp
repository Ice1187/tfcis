#include <iostream>
#include <algorithm>	//define __gcd(x, y)
#include <sstream>
using namespace std;

void reduction(long long &c, long long &m){
	long long gcd = __gcd(c,m);
	c /= gcd;
	m /= gcd;
};

void mul(long long &ansc, long long &ansm, long long c,long long m){
	reduction(ansc, m);
	reduction(c, ansm);
	ansc *= c;
	ansm *= m;
}
		

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string S;
	while (getline(cin, S)){
		
		stringstream ss(S);
		string s;
		long long ansc=1,ansm=1;

		while (ss >> s){
			
			//init
			long long c,m;
			bool isslash = false;
			//isslash
			for (int i=0; i<s.size(); i++)
				if (s[i]=='/'){
					isslash = true;
					break;
				}
				
			//have slash
			if (isslash){
				char *ptr;
				c = strtol(s.c_str(), &ptr, 10);
				m = strtol(++ptr, NULL, 10);
				reduction(c, m);
			}	
			//no   slash
			else {
				c = strtol(s.c_str(), NULL, 10);
				m = 1;
			}
			//mul
			mul(ansc, ansm, c, m);
		}
		
		//output ans
		if (ansc%ansm == 0)
			cout << ansc/ansm;
		else 
			cout << ansc << '/' << ansm;
		
		cout << '\n';
	}
			

	return 0;
}

