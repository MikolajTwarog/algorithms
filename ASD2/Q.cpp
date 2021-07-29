#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

long long int x, y;
map<long long int, long long int> pot;

void eukl(long long int a, long long int b){
	if(b==0){
		return;
	}else{
		eukl(b, a%b);
		long long int temp=y;
		y=x-(a/b)*y;
		x=temp;
	}
}


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		long long int a, b, p;
		scanf("%lld%lld%lld", &a, &b, &p);
		long long int m=ceil(sqrt(p));
		/*x=1; y=0;
		eukl(p, a);
		long long int od=(y%p+p)%p;
		long long int odw=1;*/
		long long int k=1;
		for(long long int i=0; i<m; i++){
			if(pot.find(b) == pot.end())
				pot[k]=i;
			k=(k*a)%p;
		}
		//printf("%d\n", pot[k]);
		x=1; y=0;
		eukl(k, p);
		k=x;
		if(k<0)
			k+=p;
		long long int wyn=-1;
		for(long long int i=0; i<m; i++){
			if(pot.find(b) != pot.end()){
				//printf("%lld %lld %lld\n", (pot[b]+m*i), i, pot[b]);
				wyn=pot[b]+m*i;
				break;
			}
			b=(b*k)%p;
		}
		pot.clear();
		printf("%lld\n", wyn);
	}
	return 0;
}
