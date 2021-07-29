#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int orcs[100010];
int elves[100010];


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &orcs[i]);;
		for(int i=0; i<n; i++)
			scanf("%d", &elves[i]);
		sort(orcs, orcs+n);
		sort(elves, elves+n);
		int po=0, pe=0;
		int ko=n-1, ke=n-1;
		int wyn=0;
		for(int i=0; i<n; i++){
			if(orcs[po] > elves[pe]){
				po++;
				pe++;
				wyn+=200;
			}else{
				if(orcs[ko] > elves[ke]){
					ko--;
					ke--;
					wyn+=200;
				}else{
					if(orcs[po] > elves[ke])
						wyn+=200;
					if(orcs[po] < elves[ke])
						wyn-=200;
					po++;
					ke--;
				}
			}
		}
		printf("%d\n", wyn);
	}
	return 0;
}
