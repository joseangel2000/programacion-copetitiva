#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
const int max_tam = 1e5 + 3;


int main(){
	int t,n,m; cin>>t;
	while(t--){

		cin>>n>>m;
		int a[n + 2], b[n + 2], c[m + 2], sol[m + 2];
		
		bool continuar = true;
		queue<int> posicions[n + 2];
		int x = 0;
		vi diferent;

		f(i,n)
			cin>>a[i];
		f(i,n)
			cin>>b[i];
		f(i,m){
			cin>>c[i];
			if(i == m)
				break;
			posicions[c[i]].push(i);
		}
		for(int i = n; i >= 1; --i) //le doy prioridad si a[i] != b[i]
			if(b[i] == c[m] && b[i] != a[i]){
				x = i;
				sol[m] = x;
				c[m] = 0;
				a[i] = b[i];
				break;
			}
		if(x == 0){ ///si no encontre x ahora busco sin la restriccion de que sean diferentes
			for(int i = n; i >= 1; --i){
				if(b[i] == c[m]){
					x = i;
					sol[m] = x;
					c[m] = 0;
					a[i] = b[i];
					break;
				}
			}
		}

		if(x == 0){
			cout<<"NO\n";
			continue;
		}

		// elemento, posicion
		map<int,vi> mapa;
		f(i,n)
			if(a[i] != b[i])
				mapa[b[i]].pb(i);
		f(i,m){
			int num = c[i];
			if(mapa[num].empty()) //significa que el elemento en ci no necesita ser usado
				continue;
			int tam = mapa[num].size();
			int pos = mapa[num][tam - 1];
			mapa[num].pop_back();
			sol[i] = pos;
			a[pos] = b[pos];
			c[i] = 0;
		}

		f(i,n){
			if(a[i] != b[i]){
				cout<<"NO\n";
				continuar = false;
				break;
			}
		}

		f(i,m){
			if(c[i] != 0)
				sol[i] = x;
		}

		if(continuar){
			cout<<"YES\n";
			f(i,m)
				cout<<sol[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}