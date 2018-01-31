#include <iostream>
#include <cstring>
using namespace std;
bool arr[102][102];
int  sum[102][102];

int main(){
	
	memset(sum, 0, sizeof(sum));

	int n,m;
	while (cin >> n >> m && n && m){
		
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				cin >> arr[i][j];
		
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];		
			
		int ans = 0;
		for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			for (int a=i; a<=n; a++)
			for (int b=j; b<=m; b++){
				int matrix_sum = sum[a][b] - sum[i-1][b] - sum[a][j-1] + sum[i-1][j-1];
				int area = (a-i+1)*(b-j+1);
				if (matrix_sum == 0 && area > ans)
					ans = area;
			}
		
		cout << ans << '\n';
	}

	return 0;
}

