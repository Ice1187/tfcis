#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){

	int N;
	int maxlen;
	int linewords;
	int line;
	string s;
	vector<string> v;
	
	while (cin >> N){
		v.clear();
		maxlen = 0;
		for (int i=0; i<N; i++){
			cin >> s;
			v.push_back(s);
			if (s.size() > maxlen)
				maxlen = s.size();
		}

		sort(v.begin(), v.end());

		linewords = (60-maxlen)/(maxlen+2)+1;
		v.size()%linewords == 0? 
			line = v.size()/linewords:
			line = v.size()/linewords + 1;

		for (int i=0; i<60; i++) cout << "-";
		cout << '\n';
				
		for (int i=0; i<line; i++){
			for (int j=i, words=0; 
				 j<v.size() && words<linewords; 
				 j+=line,words++){
				 	
				if (words==linewords-1)	printf("%s",v[j].c_str());
				else printf("%-*s",maxlen+2,v[j].c_str());
				
			}
			cout << '\n';
		}

	}

}
