#include <iostream>
#include <string.h>
using namespace std;
char c[105][105];
bool b[105][105]={false};

// Ãä¬ÉÀË¬d?
void Find(int x,int y){

	bool X,Y;
	X>0? X=true:X=false;
	Y>0? Y=true:Y=false;
    b[x][y] = true;

//	if (X){
//		if (Y)
			if (c[x-1][y-1]=='@' && !b[x-1][y-1]) Find(x-1,y-1);
		if (c[x-1][y]  =='@' && !b[x-1][y]  ) Find(x-1,y);
    	if (c[x-1][y+1]=='@' && !b[x-1][y+1]) Find(x-1,y+1);
//    }
//	if (Y){
		if (c[x][y-1]  =='@' && !b[x][y-1])   Find(x,y-1);
		if (c[x+1][y-1]=='@' && !b[x+1][y-1]) Find(x+1,y-1);
//	}
	if (c[x][y+1]=='@'   && !b[x][y+1])   Find(x,y+1);
	if (c[x+1][y]=='@'   && !b[x+1][y])   Find(x+1,y);
	if (c[x+1][y+1]=='@' && !b[x+1][y+1]) Find(x+1,y+1);

    return ;
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

    int m,n;
    while (cin >> m >> n && (m != 0 && n != 0)){
        //initialization
        for (int i=0; i<105; i++) {
            memset(b[i],0, sizeof(b[0][0])*n );
            memset(c[i],'*', sizeof(c[0][0])*n );
        }
        int count=0;
//        cout << "init\n";
//        for (int i=0; i<m; i++){
//            for (int j=0; j<n; j++){
//                cout << b[i][j];
//            }
//            cout << '\n';
//        }
//        cout << "-------------------\n";
//

        //set map
        for (int i=0; i<m; i++){
//            cout << "set map\n";
            for (int j=0; j<n; j++){
                cin >> c[i][j];
            }
        }

        //search
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++) {
                if ( c[i][j]=='@' && !b[i][j]) {
//                    cout << "search\n x=" << i << ' ' << "y=" << j << '\n';
                    Find(i,j);
                    count++;
//                    for (int i=0; i<m; i++){
//                        for (int j=0; j<n; j++){
//                            cout << b[i][j];
//                        }
//                        cout << '\n';
//					}
				}
//				cout << count << '\n';
            }
        }


        //output
//        cout << "output\n";
        cout << count << '\n';


    }
    return 0;
}

