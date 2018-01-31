#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

string repr(string s){
	for (int i=0; i<s.size(); i++)
			isalpha(s[i])? s[i] = tolower(s[i]) : s[i] = ' ';
	sort(s.begin(), s.end());
	return s;
};

int main(){

	vector<string> v;
	map<string, int> cnt;
	string s,tmp;
	
	while (cin >> s){
		if (s[0]=='#')
			break;

		v.push_back(s);

		s = repr(s);		

		stringstream ss(s);
		while (ss >> s){
			if (cnt.count(s)==0)	cnt[s]=0;
			cnt[s]++; 
		}
	}

	vector<string> ans;
	for (int i=0; i<v.size(); i++)
		if (cnt[repr(v[i])]==1)	ans.push_back(v[i]);
	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}
