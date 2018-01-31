	#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool npm[100000000],flag1,flag2;
vector<long long int> v;

long long int c(long long int n){
	long long sq =(long long int)sqrt(n);
	for(int i=0; i<v.size();){
		if (v[i] > sq) break;
		if (n < 2)    break;
		if (n % v[i]==0){
	    	cout << "    " << v[i] << '\n';
			n = n/v[i];
			flag1 = true;
		}
		else if (n<100000000){
			if (!npm[n]){
				cout << "    " << n << '\n';
				break;
			}
			else {i++;}
		}
		else {i++;}
		
	}
	return n; 
};

int main(){
	
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	// ½è¼Æªí
	npm[0]=true;
	npm[1]=true;
	for (int i=2; i<100000000; i++){
		if (npm[i] == false){
			for (int j=i+i; j<100000000; j+=i)
				npm[j]=true;
			v.push_back(i);
		}
	}
	
	long long int n,r;  
		while (cin >> n && n>=0){ 
		flag1 = false;	
		flag2 = false;        
		if (n < 100000000)
			if (!npm[n])
				cout << "    " << n << '\n';
			else
			 	c(n);
		else{
			r = c(n);
			for (long long int d=100000001; d<=(long long)sqrt(r);){
				if (r%d==0){
					cout << "    " << d << '\n';
					r = r/d;
					flag2=true;
				}
				else 
					d++;
			}
			if (r>100000000 || (!flag1 && !flag2))
				cout << "    " << r << '\n';
		}
		cout << '\n';
	}
	
	return 0;
}

