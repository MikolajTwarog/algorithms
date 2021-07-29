#include <cstdio>
#include <queue>
using namespace std;

struct event{
	int a;
	bool type;
	int numerek;
};

bool operator<(event a, event b){
	if(a.a == b.a)
		return a.type>b.type;
	return a.a>b.a;
}

priority_queue<event> q;
int tab[100010];
int ilo[100010];

int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			event a, b;
			scanf("%d%d%d", &a.a, &b.a, &ilo[i]);
			a.type=0;
			b.type=1;
			a.numerek=i;
			b.numerek=i;
			q.push(a);
			q.push(b);
		}
		int wyn=0;
		while(!q.empty()){
			event x=q.top();
			q.pop();
			if(x.type==0)
				tab[x.numerek]=wyn;
			else{
				int temp=ilo[x.numerek]-(wyn-tab[x.numerek]);
				if(temp>0)
					wyn+=temp;
			}
			//printf("%d %d %d %d\n", x.a, x.type, x.numerek, wyn);
		}
		printf("%d\n", wyn);
	}
	return 0;
}
