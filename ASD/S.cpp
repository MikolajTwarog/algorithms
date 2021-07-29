#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> g[200010];
vector<int> g2[200010];
stack<int> s;
bool od[200010];
int wyn[200010];
int u=1;

void dfs(int n){
	int a=g[n].size();
	od[n]=1;
	for(int i=0; i<a; i++){
		if(od[g[n][i]]==0)
			dfs(g[n][i]);
	}
	s.push(n);
}

void dfs2(int n){
	int a=g2[n].size();
	wyn[n]=u;
	for(int i=0; i<a; i++){
		if(wyn[g2[n][i]]==0){
			dfs2(g2[n][i]);
		}
	}
}


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			//printf("%d %d\n", a, b);
			if(a>0 && b>0){
				g[n+a].push_back(b);
				g[n+b].push_back(a);
				g2[a].push_back(n+b);
				g2[b].push_back(n+a);
			}
			if(a<0 && b>0){
				a*=-1;
				g[a].push_back(b);
				g[n+b].push_back(n+a);
				g2[a+n].push_back(n+b);
				g2[b].push_back(a);
			}
			if(a>0 && b<0){
				b*=-1;
				g[a+n].push_back(n+b);
				g[b].push_back(a);
				g2[a].push_back(b);
				g2[n+b].push_back(n+a);
			}
			if(a<0 && b<0){
				a*=-1;
				b*=-1;
				g[a].push_back(n+b);
				g[b].push_back(n+a);
				g2[n+a].push_back(b);
				g2[n+b].push_back(a);
			}
			//printf("%d %d\n", a, b);
		}
		/*for(int i=1; i<=2*n; i++){
			for(int j=0; j<g[i].size(); j++)
				printf("%d ", g[i][j]);
			printf("\n");
		}*/
		for(int i=1; i<=2*n; i++)
			if(od[i]==0)
				dfs(i);
		u=1;
		while(!s.empty()){
			int a=s.top();
			if(wyn[a]==0){
				dfs2(a);
				u++;
			}
			s.pop();
		}	
		bool nie=0;
		for(int i=1; i<=n; i++){
			if(wyn[i]==wyn[n+i])
				nie=1;
		}
		if(nie)
			printf("NIE\n");
		else{
			printf("TAK\n");
			for(int i=1; i<=n; i++){
				if(wyn[i]>wyn[n+i])
					printf("1 ");
				else
					printf("0 ");
			}
			printf("\n");
		}
		for(int i=0; i<=2*n; i++){
	//printf("%d ", wyn[i]);
			od[i]=0;
			wyn[i]=0;
			g[i].clear();
			g2[i].clear();
		}
	}
	return 0;
}

