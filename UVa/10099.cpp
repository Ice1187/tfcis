#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

struct town
{
	int t1;
	int t2;
	int prc;
}t[10000];


bool used[10000];

bool cmp(const town a,const town b){
	return a.prc > b.prc;
};

int findMINprc(int n,int r){
	
	memset(used,false,sizeof(used[0]));
	int re,brinum=0;

	for (int i=0; i<r; i++){

		if ( !(used[t[i].t1]) ){
			
		}
		if ( !used[t[i].t2] ){
			
		}
		if (i>=n-2 && brinum==n){
			
			break;
		}
		
	}
	
	return re;
};

int main()
{
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,r,c1,c2,p,Time=1;
	while (cin >> n >> r){

		if (n==0 && r==0)
			break;

		for (int i=0; i<r; i++){
			cin >> c1 >> c2 >> p;
			t[i].t1 = c1;
			t[i].t2 = c2;
			t[i].prc = p;
		}

		sort(t,t+r,cmp);

		int minprc = findMINprc(n,r);

		int S,D,T,result=0;
		cin >> S >> D >> T;
		
		result = T/(minprc-1);
		result%(minprc-1)==0 ? :result++;

		cout << "minprc=" << minprc << '\n';
		cout << "Scenario #" << Time;
		cout << "\nMinimum Number of Trips = " << result;
		cout << "\n\n";

		Time++;
	}
	
	return 0;
}
