#include <iostream>
#include <cstring>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int fcnt[28];
	int scnt[28];
	string s;
	while (cin >> n && n){
		memset(fcnt, 0, sizeof(fcnt));
		memset(scnt, 0, sizeof(scnt));
		
		for(int i=0; i<n; i++){
			cin >> s;
			fcnt[s[0]-'a']++;
			scnt[s[s.size()-1]-'a']++;
		}
		bool ans=0;
		for (int i=0; i<25; i++){
			if (fcnt[i]!=scnt[i]){
				ans = 1;
				break;
			}
		}
				
		if (ans)
			cout << "NG";
		else 
			cout << "OK";
		cout << '\n';
	}

	return 0;
}

