#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define bi __int128


bi a,b,n1,n2;
ll a1,b1;
ll m;

void solve(){

	a = a1; b = b1;
	n1 = (2 * a - 3 * b) / (b * b); // tiene que ser el techo

	n2 = (2 * a - b) / (b * b);
	vector<pair< ll, ll > > solucion;


	for(; n1 <= n2 ; ++n1){
        if(n1 <= 0) continue;
		ll k = b * n1 + 1;
		bi aux = ((b * n1 + 1) * (b * n1 + 2) - (2 * a * n1)) / 2; /// lo declaro bi por que las variables en las operaciones son bi, pero el resultado no lo es
		ll x = aux; ///////////casteo el aux

        if(  ((b * n1 + 1) * (b * n1 + 2) - (2 * a * n1)) / 2    >= 1 &&   ((b * n1 + 1) * (b * n1 + 2) - (2 * a * n1)) / 2 <= k  ){
		
            solucion.pb(mp(k, x));
        }
	}

	cout<<solucion.size()<<"\n";
	for(int i = 0 ; i < (int)solucion.size(); ++i)
		cout<<solucion[i].first<<" "<<solucion[i].second<<"\n";

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;cin>>t;
	
	while(t--){
		cin>>a1>>b1;	
		solve();
	}

	return 0;
}