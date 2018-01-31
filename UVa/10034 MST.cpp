#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct point{
	double x;
	double y;
}p[102];

double ptop(point a,point b){
	double X = a.x-b.x;
	double Y = a.y-b.y;
	return sqrt(X*X+Y*Y);
}

int P[102];
struct road{
	int a;
	int b;
	double w;
}r[10002];
bool cmp(road a,road b){
	return a.w < b.w;
};

//disjoint set
int find(int a){
	if (a == P[a])
		return a;
	return P[a] = find(P[a]);
};
void link(int a,int b){
	P[find(b)] = find(a);
};
	
int main(){
	
//  can't use	because printf >< cout
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int n;
	cin >> n;
	while (n--){
		
		//input
		int N;
		cin >> N;
		for (int i=0; i<N; i++)
			cin >> p[i].x >> p[i].y;
		
		//set line
		int k=0;
		for (int i=0; i<N-1; i++){
			for(int j=i+1; j<N; j++){
				r[k].a = i;
				r[k].b = j;
				r[k].w = ptop(p[i], p[j]);
				k++;
			}
		}
		//solve
		//init
		double ans=0;
		for (int i=0; i<N; i++)
			P[i] = i;
		//sort
		sort(r, r+k, cmp);
		//MST
		for (int i=0,t=0; i<N-1; t++){
			if (find(r[t].a) != find(r[t].b)){
				link(r[t].a, r[t].b);
				ans += r[t].w;
				i++;
			}
		}
		
		printf("%.2lf\n",ans);
		if (n!=0)
			cout << '\n';	
		
	}
		

	return 0;
}

