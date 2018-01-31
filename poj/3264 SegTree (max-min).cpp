#include <iostream>
#define maxn 50002
using namespace std;
int N, arr[maxn];
struct{
	int Max;
	int Min;
}seg[maxn<<2];

void build(int l, int r, int idx){
	
	if (l==r){
		seg[idx].Max = seg[idx].Min = arr[l];
		return;
	}
	
	int m = (l+r)>>1;
	int Lc = idx<<1;
	int Rc = Lc+1;
	build(l,   m, Lc);
	build(m+1, r, Rc);
	
	seg[idx].Max = max(seg[Lc].Max, seg[Rc].Max);
	seg[idx].Min = min(seg[Lc].Min, seg[Rc].Min);
	return;
}

int Max,Min;
void query(int n_l, int n_r, int l, int r, int idx){
	
	if (l<=n_l && n_r<=r){
		if (seg[idx].Max > Max)    Max = seg[idx].Max;
		if (seg[idx].Min < Min)    Min = seg[idx].Min;
		return;
	}
		
	int m = (n_l+n_r)>>1;
	int Lc = idx<<1;
	int Rc = Lc+1;
	
	if (m<l)
		query(m+1, n_r, l, r, Rc);
	else if (m>=r)
		query(n_l, m, l, r, Lc);
	else {
		query(n_l, m, l, r, Lc);
		query(m+1, n_r, l, r, Rc);
	}
	
	return;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int Q;
	cin >> N >> Q;
	for (int i=1; i<=N; i++)
		cin >> arr[i];
	
	build(1, N, 1);
	
	int a,b;
	for (int i=0; i<Q; i++){
		cin >> a >> b;
		
		Max = -1;
		Min = 2147483647;
		if (a>b) swap(a, b);
		query(1, N, a, b, 1);
		
		cout << Max-Min << '\n';
	}
		
	
	return 0;
}

