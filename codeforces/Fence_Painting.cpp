#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
const int max_tam = 1e5 + 3;

int n, m, aux;


int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		bool continuar = true;
		int a[n + 3], b[n + 3], have[n + 3], sol[m + 3], c[m + 3];
		vi use[n + 3];
		int pos_reciclabel = 0;
		bool tengo  = false;
		int x = 2;

		for(int i = 1; i<= n; ++i)
			have[i] = 0;
		for(int i = 1; i <= n; ++i){
			cin>>a[i];
			have[a[i]] = i;
		}
		for(int i = 1; i <= n; ++i)
			cin>>b[i];
		for(int i = 1; i <= m ; ++i){
			cin>>c[i];
			if(have[c[i]] != 0){
				tengo = true;
				pos_reciclabel = have[c[i]];
			}
			use[c[i]].pb(i);
		}

		for(int pos = 1; pos <= n; ++pos){
			if(a[pos] == b[pos])
				continue;
			if(use[b[pos]].empty()){
				//cout<<"\n me mori en el use b pos\n\n";
				continuar = false;
				cout<<"NO\n";
				break;
			}
			int tam = use[b[pos]].size();
			if(use[b[pos]][tam - 1] == m)
				x = pos;
			sol[use[b[pos]][tam - 1]] = pos;
			c[use[b[pos]][tam - 1]] = 0;
			use[b[pos]].pop_back();	
		}
		for(int i = 1; i <= m ; ++i){
			if(c[i] == 0)
				continue;
			if(have[c[i]] == 0){
				sol[i] = x;
				//cout<<"\nme mori en el have\n";
				continuar = false;
				cout<<"NO\n";
				break;
			}
			sol[i] = have[c[i]];
		}


		if(continuar){
			cout<<"YES\n";
			for(int i = 1; i <= m ; ++i){
				cout<<sol[i];
				if(i < m)
					cout<<" ";
			}
			cout<<"\n";
		}



	}
	return 0;
}