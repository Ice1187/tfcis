#include <iostream>
using namespace std;
char map[55][55];
int g;

void find(int x,int y){

//    cout << "x=" << x << " y=" << y << '\n';
    if (map[x][y]=='G') g++;

    map[x][y]='#';

    bool T = false;
    if (map[x-1][y]=='T' || map[x][y-1]=='T' ||
        map[x+1][y]=='T' || map[x][y+1]=='T')
        T = true;

    if (!T){
        //        cout << "@@\n";
        if (map[x-1][y]!='#')   find(x-1,y);
        if (map[x+1][y]!='#')   find(x+1,y);
        if (map[x][y-1]!='#')   find(x,y-1);
        if (map[x][y+1]!='#')   find(x,y+1);
    }

    return ;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w,h,px,py;
    while (cin >> w >> h) {
        //init
        px = py = g = 0;
        //set map
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                cin >> map[i][j];
                if (map[i][j]=='P'){
                    px = i;
                    py = j;
                }
            }
        }

        //compute
        find(px,py);

        //output
        cout << g << '\n';

    }

    return 0;
}

