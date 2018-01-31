#include <iostream>
#include <vector>
using namespace std;
int arr[15];
int result[7];
int k;
void backtrack(int n,int c){
	if (c==0){
		for (int i=6; i>0; i--){
			cout << result[i];
			if (i!=1)	cout << ' ';
		}
		cout << '\n';
		return ;
	}
		//arr locat  ¼h 
	for (int i=n; i<=k-c; i++){
		result[c] = arr[i]; 
		
//	cout << "c=" << c << '\n';
		backtrack(i+1, c-1);
	}
};

int main(){

//	freopen("out.txt","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	bool space=false;
	while (cin >> k && k!=0){
		if (space)
			cout << '\n';
		space = true;
		
		for (int i=0; i<k; i++){
			cin >> arr[i];	
		}
		backtrack(0,6);
	}

	return 0;
}

