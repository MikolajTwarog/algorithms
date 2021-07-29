#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char tab[2000010];
int pal[2000010];

int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		char temp[1000010];
		scanf("%s", &temp);
		int n=strlen(temp);
		int o=0;
		for(int i=1; o<n; i+=2){
			tab[i]=temp[o];
			tab[i+1]='#';
			o++;
		}
		tab[0]='#';
		n=strlen(tab+1);
		for(int i=1; i<=n; i++)
			pal[i]=1;
		int ip=0;
		for(int i=1; i<=n; i++){
			if(i<pal[ip]+ip-1)
				pal[i]=min(pal[ip-(i-ip)], pal[ip]+ip-1-i);
			int j=pal[i];
			while(tab[i-j]==tab[i+j]){
				pal[i]++;
				ip=i;
				j++;
			}
		}
		//for(int i=0; i<=n; i++)
		//	printf("%d ", pal[i]);
		int y;
		scanf("%d", &y);
		while(y--){
			int a, b;
			scanf("%d%d", &a, &b);
			if(pal[a+b-1]>2*b-(a+b))
				printf("TAK\n");
			else
				printf("NIE\n");
		}
	}
	return 0;
}
