#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,a;
	long long sum=0, max_sum=-2147483649;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a;
		sum += a;
		// �������t���ɭԡA�n��Ĥ@�ӭt�Ʒ��סC 
		if (sum > max_sum)
			max_sum = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << max_sum << '\n';

	return 0;
}

