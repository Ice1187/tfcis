#include <iostream>
using namespace std;
unsigned int n,m;
long long arr[100005];

struct Node{
    
    long long Max;
    long long Min;

} seg[100005*4];

void build(int l, int r, int pos){
    
    if (l==r){
        seg[pos].Max = seg[pos].Min = arr[l];
        return;
    }
    
    int m  = (l+r)>>1;
    int LC = pos<<1;
    int RC = LC|1;
    
    build(l, m, LC);
    build(m+1, r, RC);
    
    seg[pos].Max = max(seg[LC].Max, seg[RC].Max);
    seg[pos].Min = min(seg[LC].Min, seg[RC].Min);
    
}

long long Max, Min;
void query(int nl, int nr, int tl, int tr, int pos){
    
    if ((tl <= nl && nr <= tr)){
        if (seg[pos].Max > Max) Max = seg[pos].Max;
        if (seg[pos].Min < Min) Min = seg[pos].Min;
        return;
    }
    
    int m = (nl+nr)>>1;
    int LC = pos<<1;
    int RC = LC|1;
    
    if (m < tl)
        query(m+1, nr, tl, tr, RC);
    else if (m >= tr)
        query(nl, m, tl, tr, LC);
    else {
        query(nl, m, tl, tr, LC);
        query(m+1, nr, tl, tr, RC);
    }
    
};


int main() {
    
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> arr[i];
    
    build(1, n, 1);
    
    int x,y;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        
        Max = -1;
		Min = 214748364800;
		if (x>y)	swap(x, y);
        query(1, n, x, y, 1);
        
        cout << Max-Min << '\n';
        
    }
    
    
    return 0;
}
