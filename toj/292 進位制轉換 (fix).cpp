#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    string c_;
    long long a,b,c=0,r;
    cin >> a >> b >> c_;

    if (c_=="0")
        cout << 0 << endl;
    
	else {
        for (int i=c_.size(),n=0; i>0 ; i--,n++){
            c += (c_[i-1]-48)*pow(a,n);
        }
       
	    while (c!=0){
            r = c%b;
            c = c/b;
            s.push(r);
        }
       
	    while (!s.empty()){
            cout << s.top();
            s.pop();
        }
        cout <<endl;
    }
    
    return 0;
}

