#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int tab[3001][3001];
string a;
string b;
string c;

int main(){
	int z;
	scanf("%d", &z);
	while(z--){
		cin>>a>>b;
		//scanf("%s", &b);
		for(int i=1; i<=a.size(); i++){
			for(int j=1; j<=b.size(); j++){
				if(a[i-1]==b[j-1])
					tab[i][j]=tab[i-1][j-1]+1;
				else
					tab[i][j]=max(tab[i][j-1], tab[i-1][j]);
			}
		}
		/*for(int i=0; i<=a.size(); i++){
			for(int j=0; j<=b.size(); j++){
				printf("%d ", tab[i][j]);
			}
			printf("\n");
		}*/
		int u=0;
		int q=a.size(), r=b.size();
		//printf("%d %d\n", q, r);
		while(q>0 && r>0){
			if(tab[q][r]==tab[q-1][r]){
				q--;
				//printf("%d %d\n", q, r);
				continue;
			}
			if(tab[q][r]==tab[q][r-1]){
				r--;
				//printf("%d %d\n", q, r);
				continue;
			}
			c+=b[r-1];
			q--;
			r--;
			//printf("%c %d %d\n", c[u], q, r);
			u++;
		}
		cout<<tab[a.size()][b.size()]<<endl;
		for(int i=u-1; i>=0; i--)
			cout<<c[i];
		cout<<endl;
		c.clear();
	}
	return 0;
}
