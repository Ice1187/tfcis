#include <iostream>
#include <string.h>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	string X,Y;
	int x[260], y[260], z[550];   //Warnint : z > (10^250 * 10^250)
	while (cin >> X >> Y){
		//"0" throw out!
		if (X=="0" || Y=="0"){
			cout << 0 << '\n';
			continue;
		}
		
		//init
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(z, 0, sizeof(z));
		
		//char reverse
		for (int i=X.size()-1, j=0; i>=0; i--, j++)
			x[j] = X[i]-48;
		for (int i=Y.size()-1, j=0; i>=0; i--, j++)
			y[j] = Y[i]-48;
		
		//mult
		for (int i=0; i<Y.size(); i++){
			for (int j=0; j<X.size(); j++){
				z[i+j] += y[i]*x[j];
			}
		}
		
		//¶i¦ì 
		for (int i=0; i<(Y.size()-1 + X.size()-1) ; i++){
			z[i+1] += z[i]/10;
			z[i] %= 10;
		}
		
		//output +! ? 
		if (z[X.size()+Y.size()-1] != 0)
			cout << z[X.size()+Y.size()];
		//output
		for (int i=X.size()+Y.size()-2; i>=0; i--)
			cout << z[i];
		cout << '\n';
		
	}

	return 0;
}

