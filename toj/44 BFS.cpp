#include <iostream>
#include <queue>
#define pii pair
#define qx q.front().first
#define qy q.front().second
using namespace std;
int N,M,sx,sy,ex,ey;
int m[1005][1005];
bool Find = false;
queue<pii<int, int>> q;

void input (){
    
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> m[i][j];
    cin >> sx >> sy;
    cin >> ex >> ey;

};

int check(int x,int y){
    
    if (x>=N || y>=M) return 0;
    
    if (x==ex && y==ey) return Find = 1;
    if (m[x][y]==0){
//        cout << "push: " << x << ' ' << y << '\n';
        q.emplace(x, y);
        m[x][y] = 1;
        return 1;
    }
    
    return 0;
};

int BFS(){
    
    int t=1,a=1,b=0;
    while (!q.empty()) {
        while (a) {
//            cout << "a: " << a << '\n';
            a--;
            int x=qx, y=qy;
        
            q.pop();
        
            if (x>0)
                b += check(x-1, y);
            if (y>0)
                b += check(x, y-1);
            b += check(x, y+1);
            b += check(x+1, y);
        
            if (Find)
                return t;
        }
//        cout << "b:" << b << '\n';

        if (a==0){
//            cout << t << "++\n";
            t++;
            a = b;
            b = 0;
        }
        
    }
    
    return -1;
    
};

void solve(){
    
    int r;
    q.emplace(sx,sy);
    m[sx][sy] = 1;
    r = BFS();
    cout << r << '\n';
    
};

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    solve();
    
    return 0;
}
