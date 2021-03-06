#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
const long long int mod = 1e9 + 7;
const int max_tam = 1e3 + 3;

ll fact[max_tam], fac_inv[max_tam];

ll fast_pow(ll a, ll b){
	ll c = 1;
	ll a_1 = a ;
	a_1 %= mod;
	ll b_1 = b;
	while(b_1 > 0){
		if(b_1%2) c *= a_1;
		c %= mod;
		a_1 *= a_1; 
		a_1 %= mod;
		b_1 /= 2;
	}
	c %= mod;
	return c;
}


ll combinaciones(ll a,ll b){
	if(a == b || b == 0)
		return 1;
	ll ans = fact[a] * fac_inv[a - b];
	ans %= mod;
	ans *= fac_inv[b];
	ans %= mod;
	return ans;
}




void solve(){
	int n, k, aux;
	vi vec;
	cin>>n>>k;
	int hay[n + 2];
	f(i,n)
		hay[i] = 0;
	f(i,n){
		cin>>aux; vec.pb(aux);
		hay[aux]++;
	}

	sort(vec.begin(), vec.end());
	int num = -2, cantidad = 0 ;
	for(int i = n - 1; i >= n - k; --i){
		if(vec[i] != num){
			num = vec[i];
			cantidad = 1;
			continue;
		}
		cantidad++;
	}
	int cant_tot = hay[num];
	//cout<<"la cantidad total son "<<cant_tot<<"  cantidad = "<<cantidad<<endl;
	cout<<combinaciones(cant_tot, cantidad)<<"\n";	


}

int main(){
	int t;cin>>t;
	fact[1] = 1;
	fac_inv[1] = 1;
	for(int i = 2; i < max_tam; ++i){
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		fac_inv[i] = fast_pow(fact[i], mod - 2);
	}

	while(t--){
		solve();		
	}
	return 0;
}