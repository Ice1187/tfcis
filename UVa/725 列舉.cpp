#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int n;
	int a,b;
	bool c[10];
	bool printflag, noneflag, first=1;
	while (cin >> n && n){
		if (!first)
			cout << '\n';
		noneflag = true;
		first = 0;
		for (int i=1234; i<98765; i++){
			b = i;
			a = b*n;
			if (a > 98765)
				break;
			
//			cout << a << ' ' << b << '\n'; 
			
			printflag = true;
			memset(c, false, sizeof(c));
			
			for (int j=0; j<5; j++){
				c[a%10] = true;
				c[b%10] = true;
				a /= 10;
				b /= 10;
			}
			for (int k=0; k<10; k++){
				if (!c[k]){
					printflag = false;		
					break;
				}
			}
			if (printflag){
				printf("%05d / %05d = %d\n", i*n, i, n);	
				noneflag = false;
			} 	
		}
		if (noneflag)
			printf("There are no solutions for %d.\n", n);	
	}
				

	return 0;
}

