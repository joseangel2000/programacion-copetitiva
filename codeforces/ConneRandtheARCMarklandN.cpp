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

	int t, n, s, k, aux;
	cin>>t;
	while(t--){
		cin>>n>>s>>k;
		map<int,int> mapa;
		for(int i = 1; i <= k; ++i){
			cin>>aux;
			mapa[aux] = 1;
		}
		if(mapa[s] == 0){
			cout<<0<<"\n";
			continue;
		}

		int abajo = 0, arriba = 0 ;

		//idx = s;
		while(true){
			abajo++;
			if(s - abajo <= 0){
				abajo = n + 1;
				break;
			}
			if(mapa[s - abajo] == 0)
				break;
		}
		while(true){
			arriba++;
			if(s + arriba > n ){
				arriba = n + 1;
				break;
			}
			if(mapa[s + arriba] == 0)
				break;
		}
		cout<<min(arriba,abajo)<<"\n";
	}

	return 0;
}