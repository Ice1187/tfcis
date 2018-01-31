	#include <iostream>
	using namespace std;

	int main()
	{
		long long a,v=0,d=0,p=0;
		cin >> a;
		long long b[a];
		for(long long i=0;i<a;i++){
			cin>>b[i];
			
			if(b[i]==1){p++;}

			else if(b[i-1]==b[i]){  v++;}
			}

		if(p==a){b[0]=0;}

		else if(v!=a){
		for(long long i=0;i<a;i++){
			long long c=0;
			for(long long j=0;j<a;j++){
			if(b[i]<b[j]){
				c=b[j];
				b[j]=b[i];
				b[i]=c;}
			}
			if(i==a-1&&d==0) {
				b[i]=1; d++; i=0;
			}
		}	}
		else{  b[0]=1;  }

		for(int k=0;k<a;k++)
		{
			if(k==a-1){cout<<b[k];break;}
			cout<<b[k]<<" ";}

		cout<<"\n";

	return 0;
	}

