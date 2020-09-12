#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,aux;cin>>t;
	
	while(t--){

		int n ; cin>>n;
		vi vec;
		ll suma = 0ll;
		for(int i = 1; i <= n ; ++i){
			cin>>aux;
			vec.pb(aux);
			if(i != 1)
				suma = suma + fabs(aux - vec[(int)vec.size() - 2]);
		}



		bool yes[n+2];
		floop(i,n+2) yes[i] = 1;
		int cont = 0;
		for(int i = 1 ; i < n-1; ++i){
			if((vec[i-1] < vec[i] && vec[i] < vec[i+1]) || (vec[i-1] > vec[i] && vec[i]> vec[i+1])){
				cont++;
				yes[i] =0 ;
			}
		}

		cout<<n-cont<<"\n";
		for(int i = 0; i < n ; ++i){
			if(yes[i] == 1) cout<<vec[i]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}