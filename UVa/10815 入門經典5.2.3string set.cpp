#include <iostream>
#include <set>
#include <sstream> 
using namespace std;

set<string> dict;

int main(){

	string s,tmp;
	while (cin >> s){
		
		for (int i=0; i<s.size(); i++)
			if (isalpha(s[i])) 
				s[i] = tolower(s[i]);
			else 
				s[i] = ' ';
											//maybe s=" alan"
		stringstream ss(s);
		while (ss >> tmp) dict.insert(tmp); //insert "alan"
	}
	for (set<string>::iterator it=dict.begin(); it!=dict.end(); it++)
		cout << *it << '\n';

	return 0;
}
