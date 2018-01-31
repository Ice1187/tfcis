#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
multiset<int> sp,sm;

int main()
{
    long long n;
    while (  scanf("%lld",&n) ){
        if (n==0)
            break;
        else if (n>0)
            sp.insert(n);
        else
            sm.insert(n);

		if (!sp.empty()) && (!sm.empty())){
            cout << "in" << '\n';
            if ( *sm.begin()==-1 ){
                cout << *sp.begin() << ' ';
                sp.erase(*sp.begin());
            }
            else if ( *sm.begin()==-2 ){
                cout << *sp.begin() << ' ';
                sp.erase(*sp.begin());
            }
        }
   }
    cout << '\n';
    return 0;
}
