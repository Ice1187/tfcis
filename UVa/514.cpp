#include <iostream>
#include <stack>
using namespace std;

stack<int> s,a,b;

int main()
{
    while(1){
	    int n;
	    cin >> n;
	    if (n==0)
			break;

	    while(1){
	  		int input;
	  		bool flag=0;
	    	for (int i=0; i<n; i++){
	      		cin >> input;
		  		if (input==0)
		   	   		break;
		   		s.push(input);
	   	    }
	   	    
	   		if(!input)
	        	break;

			a.push(s.top());
			s.pop();
			for(;!s.empty();s.pop()){
		        while(!a.empty() && a.top()>s.top()){
		            b.push(a.top());
		            a.pop();
		        }
		        a.push(s.top());
		    }

		    while(!a.empty()){
		     	b.push(a.top());
		        a.pop();
			}

		    for(int i=1;i<=n;i++){

		       if(b.top()!=i){
		           flag = 1;
		           break;
		       }
		       b.pop();
		    }
		    if(flag==1){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
		}
		cout << endl;
	}
	    return 0;
}
