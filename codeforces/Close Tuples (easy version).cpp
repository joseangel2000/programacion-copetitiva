#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 

ll combinaciones (ll n, ll k){
	if(n == 0)
		return 0;
	if(k == 2){
		if(n < 2)
			return 0;
		return (n * (n - 1)) / 2;
	}
	if(n < 3)
		return 0;
	return (n * (n - 1) * (n - 2)) / 6;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t, aux, n;
	cin>>t;
	while(t--){
		cin>>n;
		map<ll,ll> mapa, mapa_aux;
		f(i, n){
			cin>>aux;
			mapa[aux]++;
			mapa_aux[aux]++;
		}
		ll sol = 0;
		for(map<ll,ll>::iterator idx = mapa.begin() ; idx != mapa.end(); ++idx){
			ll num1 = idx->first; ll cantidad = idx->second;
			ll cantidad_2 = mapa_aux[num1 + 1];
			ll cantidad_3 = mapa_aux[num1 + 2];

			sol = sol + combinaciones(cantidad, 3);             //aaa
			sol = sol + combinaciones(cantidad, 2) * cantidad_2;//aab
			sol = sol + combinaciones(cantidad, 2) * cantidad_3;//aac
			sol = sol + cantidad * combinaciones(cantidad_2, 2);//abb
			sol = sol + cantidad * combinaciones(cantidad_3, 2);//acc
			sol = sol + cantidad* cantidad_2 * cantidad_3;
		}
		cout<<sol<<"\n";

	}
	

	return 0;
}