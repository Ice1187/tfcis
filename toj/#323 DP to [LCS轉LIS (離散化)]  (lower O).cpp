#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N[10002];
int K[10002];
int C[10002];
vector<int> v;


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int nc,Ktime;
    
    //input
    cin >> nc >>Ktime;
    for (int i=1; i<=nc; i++)
        cin >> N[i];
    
    //Â÷´²¤Æ - 1  (set correspond num) 
    for (int i=1; i<=nc; i++)
        C[N[i]] = i;
    
    
    while (Ktime--){
        //init
        v.clear();
        
        //input 
        for (int i=1; i<=nc; i++){
            cin >> K[i];
            //Â÷´²¤Æ  - 2  (change to corresonding num) 
            K[i] = C[K[i]];
        }
        
        //LIS
        v.emplace_back(K[1]);
        for (int i=2; i<=nc; i++){
            int a=K[i];
            if (a > v.back())
                v.emplace_back(a);
            else
                *lower_bound(v.begin(), v.end(), a) = a;
        }
        
        //output
        cout << v.size();
        
        //next
        cout << '\n';    
    }
    

    return 0;
}
