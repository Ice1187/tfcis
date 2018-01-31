#include <iostream>
using namespace std;
int se[1000010];

int find(int a){
	if (se[a]==a)
		return a;
	return se[a] = find(se[a]);
};

//b 連結到 A
void link(int a,int b){
	se[find(b)] = find(a);
	return ;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,a,b,an,bn;
	string str,str1,str2,str3;
	cin >> n;

	for (int i=1; i<=2*n; i++)	{se[i] = i;}

	while (cin >> str1 >> str2 >> str3 >> a >> b){
		str = str1+str2+str3;
		
		an = a+n, bn = b+n; 

		if (str=="youarefriends"){
			if (find(an)==find(b) || find(bn)==find(a)){
				cout << "angry\n";
				continue;
			}
			//b link A
			link(a,b);
			link(an,bn);
		}

		else if (str == "youareenemies"){
			if (find(a)==find(b) || find(an)==find(bn)){
				cout << "angry\n";
				continue;
			}
			//b link B
			link(b,an);
			link(a,bn);
		}

		else if (str == "areyoufriends"){
			//find (A==B)? 
			find(a)==find(b) ? cout << "yeap\n":cout << "nope\n";
		}

		else if (str == "areyouenemies"){
			//find (A!=B)?
			((find(a)==find(bn))||(find(an)==find(b))) ? cout << "yeap\n":cout << "nope\n";
		}

	}

	return 0;
}