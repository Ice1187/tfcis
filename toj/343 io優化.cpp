#include <iostream>
using namespace std;

int main(){
 
 	ios::sync_with_stdio(false);
 	cin.tie(0);

    int N,max=0,min=1000000010;
    cin >> N;
    int n;
    for (int i=0; i<N; i++){
        cin >> n;
        if (n>max)
            max = n;
        if (n<min)
            min = n;
    }
        
    if (max==min)
        cout << "Same!\n";
    else
        cout << max << ' ' 
             << min << '\n';
        
    return 0;
}
