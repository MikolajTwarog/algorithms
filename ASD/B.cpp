#include <cstdio>
#include <algorithm>
using namespace std;

struct item{
	int v, w;
};

item tab[1010];
int pl[20010];

int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n, B;
		scanf("%d%d", &n, &B);
		for(int i=0; i<n; i++){
			scanf("%d%d", &tab[i].w, &tab[i].v);
		}
		for(int i=0; i<n; i++){
			for(int j=B; j>=0; j--){
				if(j>=tab[i].w){
					pl[j]=max(pl[j], tab[i].v+pl[j-tab[i].w]);
				}
			}
		}
		printf("%d\n", pl[B]);
		for(int i=0; i<=B; i++)
			pl[i]=0;
	}
	return 0;
}
