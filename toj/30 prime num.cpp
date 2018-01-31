#include <iostream>
using namespace std;
bool npm[1000010]={0};
int  pmn[1000010]={0};

int main(int argc, char const *argv[])
{
	int k = 0;
	npm[0] = true;
	npm[1] = true;
	pmn[2] = 1;
	for (int i=2; i<1000010; i++){
		if ( !npm[i] ){
			k++;
			for (int j=i; j<1000010; j+=i)
				npm[j] = true;
		}
		pmn[i] = k;
	}


	int n;
	while (cin >> n){
		cout << pmn[n] << '\n';
	}
	return 0;
}
