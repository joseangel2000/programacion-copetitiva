#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n, c0 = 0, c1 = 0, c2 = 0, aux;
		cin>>n;
		int ans = 0;
		f(i, n){
			cin>>aux;
			if(aux % 3 == 0)
				c0++;
			if(aux % 3 == 1)
				c1++;
			if(aux % 3 == 2)
				c2++;
		}
		int balanced = n / 3;
		if(c0 > balanced && c1 < balanced){
			aux = min(c0 - balanced, balanced - c1);
			ans += aux;
			c0 -= aux;
			c1 += aux;
		}
		if(c1 > balanced && c2 < balanced){
				aux = min(c1 - balanced, balanced - c2);
				ans += aux;
				c1 -= aux;
				c2 += aux;
		}		
		
		if(c2 > balanced && c0 < balanced){
				aux = min(c2 - balanced, balanced - c0);
				ans += aux;
				c2 -= aux;
				c0 += aux;
			
		}
		if(c0 > balanced && c2 < balanced){
			aux = min(c0 - balanced, balanced - c2);
			ans = ans + 2*aux;
			c0 -= aux;
			c2 += aux;
		}
		if(c1 > balanced && c0 < balanced){
			aux = min(c1 - balanced, balanced - c0);
			ans = ans + 2* aux;
			c1 -= aux;
			c0 += aux;
		}
		if(c2 > balanced && c1 < balanced){
			aux = min(c2 - balanced, balanced - c1);
			ans = ans + 2 * aux;
			c2 -= aux;
			c1 += aux;
		}
		cout<<ans<<"\n";

	}

	return 0;
}