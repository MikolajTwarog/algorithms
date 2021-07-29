#include <cstdio>
using namespace std;

unsigned long long int A[81][81];
unsigned long long int vec[81];
unsigned long long int B[81][81];
int y;

void mnozenie(int n, bool kt){
	unsigned long long int C[n+1][n+1];
	for(int i=0; i<=y; i++){
		for(int j=0; j<=y; j++)
			C[i][j]=0;
	}
	if(kt==1)
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					C[i][j]+=B[i][k]*A[k][j];
					C[i][j]=C[i][j]%1000;
				}
			}
		}
	else
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					C[i][j]+=A[i][k]*A[k][j];
					C[i][j]=C[i][j]%1000;
				}
			}
		}
	if(kt==1)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				B[i][j]=C[i][j];
	else
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				A[i][j]=C[i][j];
	return;
}

void pot(int n){
	while(n>0){
		if(n%2==1)
			mnozenie(y, 1);
		mnozenie(y, 0);
		n/=2;
	}
	return;
}


int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int m;
		scanf("%d%d", &y, &m);
		for(int i=0; i<y; i++)
			scanf("%llu", &A[0][i]);
		for(int i=0; i<y; i++)
			scanf("%llu", &vec[i]);
		for(int i=0; i<y; i++){
			A[0][i]=A[0][i]%1000;
			vec[i]=vec[i]%1000;
		}
		for(int i=0; i<y; i++){
			for(int j=1; j<y; j++){
				if(j==i+1)
					A[j][i]=1;
				else
					A[j][i]=0;
			}
		}
		for(int i=0; i<=y; i++){
			for(int j=0; j<=y; j++){
				if(i==j)
					B[i][j]=1;
				else
					B[i][j]=0;
			}
		}
		pot(m-y);
		//mnozenie(y, 1);
		unsigned long long int wyn=0;
		for(int i=0; i<y; i++){
			wyn+=B[0][i]*vec[i];
			wyn=wyn%1000;
		}
		if(m<=y)
			printf("%03llu\n", vec[y-m]);
		else
			printf("%03llu\n", wyn);
		/*printf("B\n");
		for(int i=0; i<y; i++){
			for(int j=0; j<y; j++)
				printf("%d ", B[i][j]);
			printf("\n");		
		}
		printf("A\n");
		for(int i=0; i<y; i++){
			for(int j=0; j<y; j++)
				printf("%d ", A[i][j]);
			printf("\n");		
		}*/
	}
	return 0;
}
