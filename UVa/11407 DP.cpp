#include <iostream>
using namespace std;
int n[10002]; 

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	//Squares list 
	int squ[102];
	for (int i=1; i<=100; i++)
		squ[i] = i*i;
	
	//compute
	//init t
	for (int i=1; i<=10000; i++)
			n[i] = i;
	
	for (int i=2; squ[i]<=10000; i++){
		for (int j=squ[i]; j<=10000; j++){
			if (n[j-squ[i]]+1 < n[j])
				n[j] = n[j-squ[i]]+1;
		}
	}
	
	int N,a;
	cin >> N;
	while (N--){
		//input
		cin >> a;
		
		//output
		cout << n[a] << '\n';
	}

	return 0;
}

