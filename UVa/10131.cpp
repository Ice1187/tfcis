#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> s;
struct Ele 
{
	int num;
	int wight;
	int smart;
	int ordinal;
	int previous;
	
}e[1005];

bool wg_cmp(const Ele a,const Ele b){
	return a.wight < b.wight;
};

bool num_cmp(const Ele a,const Ele b){
	return a.num < b.num;
};

int set(int n){
	int max=0;
	for (int i=0; i<n; i++){
		if (e[i].smart < e[n].smart){
			max = i;
		}
	}	
};

int main()
{
	int tmp1,tmp2,count=1;
	while (cin >> tmp1 >> tmp2){
		e[count].num   = count;
		e[count].wight = tmp1;
		e[count].smart = tmp2;
		count++;
	}
	
	sort(e,e+count,wg_cmp);    //wight sort finish

	int ord,max=1,pv,maxnum;
	for (int i=1; i<count; i++){
		pv = e[i].num;
		ord = 1;
		for (int j=0; j<i; j++){
			if (e[i].smart < e[j].smart && e[i].wight != e[j].wight )
				if (e[j].ordinal >= ord){
					ord = e[j].ordinal + 1;
					pv  = e[j].num;
				}
		}
		
		if (ord>max){
			max = ord;
			maxnum = e[i].num;
		}
		
		e[i].ordinal = ord;
		e[i].previous = pv;
	}

	sort(e,e+count,num_cmp);

	int left,right,mid,ord_num=maxnum;
	while (left < right){
		mid = (left + right)/2;
		if (e[mid].num == ord_num)
			break;
		else if (e[mid].num > ord_num)
			right = mid-1;
  		else if (e[mid].num < ord_num)
			left = mid+1;
	}

	cout << max << '\n';    //output max

//	for (int i=1; i<count; i++){
//		cout << "e[i].num"<< "   " << e[i].num
//			<<  "\ne[i].previous   " << e[i].previous << "\n"
//			<< "e[i].ordinal   " << e[i].ordinal << '\n';
//	}
	while (ord_num != e[ord_num].previous){
		s.push(ord_num);
		ord_num = e[ord_num].previous;
	}
	s.push(ord_num);

	while(!s.empty()){
		cout << s.top() << '\n';
		s.pop();
	}
	
	return 0;
}


/*
3 500 2000   1
4 1000 4000  1
5 1100 3000  2 < 4
9 2000 1900  3 < 5
2 6000 2100  3 < 5
6 6000 2000  3 < 5
8 6000 1200  4 < 9
1 6008 1300  4 < 9
7 8000 1400  4 < 9

1 6008 1300  4 < 9
2 6000 2100  3 < 5
3 500 2000   1
4 1000 4000  1
5 1100 3000  2 < 4
6 6000 2000  3 < 5
7 8000 1400  4 < 9
8 6000 1200  4 < 9
9 2000 1900  3 < 5


8 6000 1200  4 < 9
9 2000 1900  3 < 5
5 1100 3000  2 < 4
4 1000 4000  1
*/

