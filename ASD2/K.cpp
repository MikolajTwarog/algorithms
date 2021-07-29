#include <cstdio>
#include <cstring>
using namespace std;

char tab[1000010];
int sd[1000010];


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		scanf("%s", &tab[1]);
		int n=strlen(tab+1);
		sd[0]=-1;
		for(int i=1; i<=n; i++){
			int j=i-1;
			while(j>0 && tab[i]!=tab[sd[j]+1])
				j=sd[j];
			sd[i]=sd[j]+1;
		}
		//for(int i=0; i<=n; i++)
		//	printf("%d ", sd[i]);
		if(n%(n-sd[n])>0)
			printf("1\n");
		else
			printf("%d\n", n/(n-sd[n]));
	}
	return 0;
}
