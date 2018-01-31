#include <iostream>
#include <vector>
using namespace std;
const int maxn=30;
vector<int> v[maxn];
int N;
void find_block(int a, int &p, int &h){
	for (int i=0; i<N; i++)
		for (int j=0; j<v[i].size(); j++)
			if (v[i][j]==a){
				p = i;
				h = j;
				return;
			}
}

void clear_above(int p, int h){
	for (int i=h+1; i<v[p].size(); i++){
		int b = v[p][i];
		v[b].push_back(b);
	}
	v[p].resize(h+1);
}

void pile_onto(int pa, int ha, int pb){
	for (int i=ha; i<v[pa].size(); i++)
		v[pb].push_back(v[pa][i]);

	v[pa].resize(ha);
}

void print(){
	for (int i=0; i<N; i++){
		printf("%d:",i);
		for (int j=0; j<v[i].size(); j++)
			printf(" %d",v[i][j]);
		printf("\n");
	}
}

int main(){
	
	int a,b;
	string s1,s2;
	
	cin >> N;
	for (int i=0; i<N; i++) v[i].push_back(i);

	while (cin >> s1 >> a >> s2 >> b){
	
		if (s1=="quit")	break;

		int pa,ha,pb,hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if (pa==pb)	continue;
		if (s1=="move")	clear_above(pa,ha);
		if (s2=="onto") clear_above(pb,hb);
		pile_onto(pa, ha, pb);
	}
	print();
	return 0;
}
