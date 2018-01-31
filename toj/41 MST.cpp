#include <iostream>
#include <algorithm>
using namespace std;
int K[1005];
struct Road{
	int a,b,w;
}r[500005];

bool cmp(const Road a,const Road b){
	return a.w<b.w;
};

int find(int a){
	if (K[a]==a)
		return a;
	return K[a]=find(K[a]);
};

void link(int a,int b){
	K[find(b)] = find(a);
	return;
};

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int k,R;
	cin >> k >> R;
	for (int i=0; i<k; i++)
		K[i]=i;
	for (int i=0; i<R; i++){
		cin >> r[i].a >> r[i].b >> r[i].w;
	}
	
	sort(r, r+R, cmp);
	
	int i1=k-1,money=0;
	for (int i=0; i<R; i++){
		if (find(r[i].a) != find(r[i].b)){
			link(r[i].a, r[i].b);
			money += r[i].w;
			i1--;
		}
		if (!i1)	break;
	}
	
	i1?
	cout << "-1\n": 
	cout << money << "\n";
	
	return 0;
}
