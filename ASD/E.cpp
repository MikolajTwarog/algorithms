#include <cstdio>
#include <algorithm>
using namespace std;

int tab[2010];
int wyna[2010][2010];
int wynb[2010][2010];


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				wyna[i][j]=0;
				wynb[i][j]=0;
			}
		}
		int sum=0;
		for(int i=0; i<n; i++){
			scanf("%d", &tab[i]);
			sum+=tab[i];
		}
		for(int i=1; i<=n; i++){
			for(int j=0; j<n; j++){
				wyna[i][j]=max(wynb[i-1][j]+tab[(j+i-1)%n], wynb[i-1][(j+1)%n]+tab[j]);
				wynb[i][j]=min(wyna[i-1][j], wyna[i-1][(j+1)%n]);
			}
		}
		/*for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				printf("%d ", wyna[i][j]);
			}
			printf("\n");
		}*/
		//printf("%d ", suma(1, n));
	//	sort(wyn[n], wyn[n]+n);
		int wyn=0;
		for(int i=0; i<n; i++){
			wyn=max(wyn, wyna[n][i]);
		}
		printf("%d %d\n", wyn, sum-wyn);
	}
	return 0;
}
