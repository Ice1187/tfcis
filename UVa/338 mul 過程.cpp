#include <iostream>
#include <string.h>
using namespace std;

int main(){
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	//declare
	int a[12],b[12],t[12][27],r[27],L,biglen,shortlen,time;
	string A,B;
	
	while (cin >> A >> B){
		
		//init
		L=time=0;
		biglen = max(A.size(), B.size());
		shortlen = min(A.size(), B.size());
	    memset(a, 0, sizeof(a));
	    memset(b, 0, sizeof(b));
	    memset(t, 0, sizeof(t));
	    memset(r, 0, sizeof(r));
    	for (int i=0; i<A.size(); i++)
		  	a[i] = A[A.size()-i-1]-'0';
		for (int i=0; i<B.size(); i++)
		  	b[i] = B[B.size()-i-1]-'0';
		
		//compute
		for (int i=0; i<B.size(); i++){
			if (b[i]==0)
				continue;
			else {
				time++;
			  	for (int j=0,x,y,z; j<A.size(); j++){
					t[i][i+j] += a[j]*b[i];
					t[i][i+j+1] += t[i][i+j]/10;
					t[i][i+j] %= 10; 
					r[i+j] += a[j]*b[i];
					r[i+j+1] += r[i+j]/10; 
					r[i+j] %= 10;
				}
			}
		}
		
		//output
		L = r[A.size()+B.size()-1]==0 ? A.size()+B.size()-1-1 : A.size()+B.size()-1;
			//A 
		for (int i=0; i<L-(A.size()-1); i++)
			cout << ' ';
		for (int i=A.size()-1; i>=0; i--)
			cout << a[i];
		cout << '\n';
			//B
		for (int i=0; i<L-(B.size()-1); i++)
			cout << ' ';
		for (int i=B.size()-1; i>=0; i--)
			cout << b[i];
		cout << '\n';
			//---
		for (int i=0; i<L-(biglen-1); i++)
			cout << ' ';
		for (int i=0; i<biglen; i++)
			cout << '-';
		cout << '\n'; 
				
			//process
				// if times = 0 
		if (A=="0" || B=="0"){
				//r
			for (int i=0; i<L; i++)
				cout << ' ';
			cout << 0;
			cout << '\n';
		}
		
				//else if times above than 1 
		else {
			if (time > 1){
				for (int i=0; i<B.size(); i++){
					if (b[i]==0)
						continue;
					int len = t[i][A.size()+i]==0? A.size()-1:A.size();
						//space
//					cout << "L=" << L << "\tlen=" << len << "\ti=" << i << '\n';
					for (int j=0; j<L-len-i; j++)
						cout << ' ';	
						//number
					for (int j=len+i; j>=i; j--)
						cout << t[i][j];
						//next
					cout << '\n';
				}
					//---
				for (int i=0; i<=L; i++)
					cout << '-';
				cout << '\n';
			}
				//r
			for (int i=L; i>=0; i--)
				cout << r[i];
			cout << '\n';
		}
		
		//next run
		cout << '\n';		
	}

	return 0;
}

