#include <iostream>
#include <cstring> 
using namespace std;
int arr[105][105];
int pre[105][105];
int n,m;

int main(){

	while (cin >> n >> m && n){
		memset(arr, 0, sizeof(arr));
		memset(pre, 0, sizeof(pre));
	
		char tmp;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				cin >> tmp;
				arr[i][j] = tmp-48;
				pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + arr[i][j];
			}
		}
		
		int cnt=0;
		for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			for (int p=i; p<=n; p++){
			for (int q=j; q<=m; q++){
				int area = (p-i+1)*(q-j+1);
				int sum = pre[p][q] - pre[i-1][q] - pre[p][j-1] + pre[i-1][j-1];
				if (area == sum)
					cnt++;
			}}
		}}
		
		cout << cnt << '\n';
	}
										

	return 0;
}





