#include <iostream>
using namespace std;
int c,n,p;
int Exp(int pow){
	
	if (pow==0)
		return 0;
	if (pow==1)
		return c;	
	
	int half = Exp(pow/2);
	
	if (pow%2 == 0)
		return half*half%p;
	else
		return (half*half%p)*c%p;
};

int main(){

	while (cin >> c >> n >> p){
		cout << Exp(n) << '\n';
	}

	return 0;
}

