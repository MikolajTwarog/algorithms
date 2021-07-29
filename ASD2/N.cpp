#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int tab[25][1000010];

struct licz{
	int v1; int v2; int i; 
};

bool por(licz a, licz b){
	if(a.v1==b.v1)
		return a.v2<b.v2;
	return a.v1<b.v1;
}

bool por2(licz a, licz b){
	if(a.v1==b.v1 && a.v2==b.v2)
		return true;
	return false;
}


bool powtuszenia(int k, int a, int b){
	int pot=1;
	int wyk=0;
	while(pot<k){
		pot*=2;
		wyk++;
	}
	if(pot>1){
		pot/=2;
		wyk--;
	}
	if(tab[wyk][a]==tab[wyk][b] && tab[wyk][a+k-pot]==tab[wyk][b+k-pot])
		return true;
	return false;
}

int bin(int a, int b, int q){
	int p=0;
	int sr;
	while(p<q){
		sr=(p+q)/2;
		if(powtuszenia(sr, a, b) || sr==0)
			p=sr+1;
		else
			q=sr;
	}
	return q;
}

int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		int n;
		scanf("%d", &n);
		int kupa[n+10][2];
		for(int i=0; i<=n; i++){
			char a;
			scanf("%c", &a);
			if(a=='L')
				tab[0][i]=1;
			else
				tab[0][i]=2;
		}
		int lol=1;
		for(int i=1; lol<n; i++, lol*=2){
			vector<licz> vec;
			for(int j=1; j<=n; j++){
				licz a;
				a.v1=tab[i-1][j];
				a.v2=tab[i-1][j+lol];
				a.i=j;
				vec.push_back(a);	
			}
			sort(vec.begin(), vec.end(), por);
			int bp=1;
			tab[i][vec[0].i]=1;
			for(int j=1; j<vec.size(); j++){
				if(por2(vec[j], vec[j-1])){
					tab[i][vec[j].i]=bp;
				}else{
					bp++;
					tab[i][vec[j].i]=bp;
				}
			}
			if(lol*2>n)
				for(int j=0; j<n; j++)
					kupa[j][0]=vec[j].i;
		}
		for(int i=0; i<n-1; i++){
			int a=bin(kupa[i][0], kupa[i+1][0], min(n-kupa[i][0], n-kupa[i+1][0])+2)-1;
			kupa[i][1]=a;
		}
		kupa[n-1][1]=0;
		int dupa[500010];
		dupa[kupa[0][0]]=kupa[0][1];
		for(int i=1; i<n; i++){
			dupa[kupa[i][0]]=max(kupa[i-1][1], kupa[i][1]);
		}
		for(int i=1; i<=n; i++){
			printf("%d ", dupa[i]);
		}
		printf("\n");
		for(int i=0; i<=n; i++)
			for(int j=0; j<20; j++)
				tab[j][i]=0;
	}
	return 0;
}











