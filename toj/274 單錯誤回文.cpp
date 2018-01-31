#include <iostream>
using namespace std;
string s;

bool srh(int l, int r, int t){	//l=¥ª  r=¥k  t=³Ñ¾l¿ù»~¦¸¼Æ 
	while (l<=r){
		if (s[l] != s[r]){
			if (t==0)	return 0;
			return max( srh(l+1, r, t-1), srh(l, r-1, t-1));	
		}
		l++;
		r--;
	}
	return 1;
}

int main(){
	bool ans;
	long long n;
	cin >> n;
	while (n--){
		cin >> s;		
		ans = srh(0, s.size()-1, 1);
		ans ? cout << "YES" : cout << "NO";
		cout << '\n';
	}
	
 	return 0;
}
