#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cost[1000010];
int tab[1000010];
long long int wyn[1000010];


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d%d", &tab[i], &cost[i]);	
		}
		int len, c;
		scanf("%d%d", &len, &c);
		wyn[0]=min(cost[0], c);
		for(int i=1; i<n; i++)
			wyn[i]=min((long long)c+wyn[upper_bound(tab, tab+n, tab[i]-len-1)-tab-1], (long long)cost[i]+wyn[i-1]);
		printf("%lld\n", wyn[n-1]);
	}
	return 0;
}
