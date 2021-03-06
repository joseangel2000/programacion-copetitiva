#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k, n, aux;
	cin>>t;
	while(t--){
		cin>>n;

		bool princess[n + 5];
		bool escogido[n + 5]; for(int i = 0; i < n + 5; ++i){
			escogido[i] = false;
			princess[i] = false;
		}

		int agarrados = 0;

		//vector<int>listas[n + 3];

		for(int i = 1; i <= n ; ++i){
			cin>>k;
			for(int j = 1; j <= k; ++j){
				cin>>aux;
				//listas[i].pb(aux);
				if(princess[i] == false){
					if(escogido[aux] == false){
						escogido[aux] = true;
						princess[i] = true;
						agarrados++;
					}
				}	
			}
		}

		/*for(int i = 1; i <= n; ++i){
			for(int j = 0; j < listas[i].size(); ++j){
				if(escogido[listas[i][j]] == false){
					escogido[listas[i][j]] = true;
					princess[i] = true;
					agarrados++;
					break;		
				}
			}
		}*/

		if(agarrados == n){
			cout<<"OPTIMAL\n";
			continue;
		}
		int princesa = 0, principe = 0;
		for(int i = 1; i<= n ; ++i){
			if(princess[i] == false)
				princesa = i;
			if(escogido[i] == false)
				principe = i;
		}

		cout<<"IMPROVE\n";
		cout<<princesa<<" "<<principe<<"\n";
	}

	return 0;
}