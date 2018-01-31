#include <iostream>
using namespace std;

void N(int s,int n){
	for (int i=0; i<s; i++){
		cout << ' ';
	}
	for (int j=0; j<2*n-1; j++){
		cout << '*';
	}
	cout << endl;
}

void N2(int n,int s=0){
	for (int a=1; a<=n; a++){
		N(n-a+s,a);
	}
}

void A(int n){
	N2(n);
}

void B(int n){
	N2(n);
	N2(n);
}

void C(int n){
	for (int c=1; c<=n; c++){
		N2(c,n-c);
	}
}

void D(int n,int e=10,int i_=0){
	n = n*e-i_;
	N2(n);
}

void E(int n){
	N2(n,2);
	for (int i=0; i<2*n+3; i++){
		cout << '#';
	}
	cout << endl;
}

void F(int n){
	D(n,2);
}

void G(int n){
	D(n,3);
}

void H(int n){
	D(n,7);
}

void I(int n){
	D(n,4,1);
}

int main(){
	int t;
	int n;
	char ch;
	cin >> t;
	while (t--){
		cin >> ch >> n;
		switch(ch){
			case 'A':
				A(n);
				break;
			case 'B':
				B(n);
				break;
			case 'C':
   				C(n);
 				break;
			case 'D':
				D(n);
				break;
			case 'E':
				E(n);
				break;
			case 'F':
				F(n);
				break;
			case 'G':
				G(n);
				break;
			case 'H':
				H(n);
				break;
			case 'I':
				I(n);
				break;
		}
		cout << endl;
	}
	return 0;
}
