#include <iostream>
using namespace std;

int main()
{
    int N;
    bool c=0;
    cin >> N;
    
    string a="",b="";
    cin >> a;
    cin >> b;
    
    for(int j=0; j<N; j++){
        
		if(a[j]=='0' && b[j]=='0'){
            c=1;
            break;
        }
        
        else if(a[j]=='0' && ((b[j-1]=='0') || (b[j+1]=='0'))){
            c=1;
            break;
        }
    }
    
    if(c)
        cout << "FENESTRATION FORTIFICATION FAILURE!" << endl;
    else
        cout << "FENDED OFF!" << endl;
        
	return 0;
}
