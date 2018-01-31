#include <iostream>
#include <cstring>
using namespace std;
short a[502][110];
short len[502];
bool used[502];

void add(int t, int x, int y){

	for (int i=0; i<max(len[x], len[y]); i++){
		a[t][i] +=  (a[x][i] + a[y][i]);
		if (a[t][i] > 9){
			a[t][i+1] += a[t][i]/10;
			a[t][i] %= 10;
		}
	}
	
	a[t][max(len[x], len[y])] != 0 ? len[t] = max(len[x], len[y])+1:
							   len[t] = max(len[x], len[y]);		   
	used[t] = 1;
};

void Do(int n){
    
    if (n<=2)
    	return;
    
    if (used[n-2] == 0)
    	Do(n-2);
    	
    if (used[n-1] == 0)
    	Do(n-1);
    	
    if (used[n] == 0)
    	add(n, n-1, n-2);
	
}

int main(){
	
	memset(a, 0, sizeof(a));
	memset(used, 0, sizeof(used));
	memset(len, 0, sizeof(len));
	
    a[0][0] = len[0] = used[0] = 1;
    a[1][0] = len[1] = used[1] = 1;
    a[2][0] = len[2] = used[2] = 1;
    
    int n;
    cin >> n;
    
    Do(n);
   	
	for (int i=len[n]-1; i>=0; i--)
   		cout << a[n][i];
   	cout << '\n';
   
    
}
