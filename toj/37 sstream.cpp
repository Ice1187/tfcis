#include <iostream>
#include <sstream>
using namespace std;

int main(){

	string str;
	
	while (getline(cin, str)){
		
		int n,t=0;
		stringstream ss(str);
		while (ss >> n)	t++;
		
		cout << t << '\n';
	}
		 

	return 0;
}

