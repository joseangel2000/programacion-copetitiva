#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

const int estro_sldfjalskdj = 2;
const int maximo = 5002;
const ll modulo = 998244353;

ll fac[maximo + 1];
ll fac_inv[maximo + 1];

ll f_pow(ll ae, ll be) {
	ll a = ae; ll b = be; 
    ll resp = 1; 
    a = a % modulo;
    while(b>0) { 
        if(b % 2) resp *= a;
        resp %= modulo; 
        b /= 2; 
        a *= a;
        a %= modulo; 
    } 
    resp %= modulo;
    return resp; 
}

ll coef_bin(ll n, ll k){

	if(k == 0 || k == n)
		return 1ll;

	ll resp = ((fac[n] % modulo * fac_inv[k]) % modulo) * fac_inv[n-k];
	resp %= modulo;
	return resp; 
}

/*ll mat[maximo][maximo];
void construye(){
	for(int i = 1 ; i < maximo; ++i){
		for(int j = 0 ; j <= i; ++j){
			if(i == j){
				mat[i][j] == 1;
				continue;
			}
			if(j == 0){
				mat[i][j] == 1;
				continue;
			}
			mat[i][j] = mat[i][j-1] + mat[i - 1]
		}
	}
}
*/


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0] = 1;
	fac_inv[0] = 1;
	for(int i = 1; i < maximo; ++i){
		fac[i] = (fac[i-1] * i) % modulo;
		fac_inv[i] = (f_pow(fac[i], modulo - 2) % modulo);
	}

	int a, b, c;
	vi vec;
	cin>>a>>b>>c;
	vec.pb(a); vec.pb(b); vec.pb(c);
	sort(vec.begin(), vec.end());
	a = vec[0]; b = vec[2]; c = vec[1];

	ll resp1 = 0ll; // b->a
	ll resp2 = 0ll; //b -> c
	ll resp3 = 0ll ; //c->a

	for(int i = 0; i <= a; ++i){
		resp1 = resp1 + ((coef_bin(b,i) * coef_bin(a, i)) % modulo * fac[i]);
		resp1 %= modulo;
	}
	for(int i = 0; i <= c; ++i){
		resp2 = resp2 + ((coef_bin(b,i) * coef_bin(c, i)) % modulo * fac[i]);
		resp2 %= modulo;
	}
	for(int i = 0; i <= a; ++i){
		resp3 = resp3 + ((coef_bin(c,i) * coef_bin(a, i)) % modulo * fac[i]);
		resp3 %= modulo;
	}

	ll respuesta_chida = 1;

	respuesta_chida = resp1 * resp2;
	respuesta_chida %= modulo;
	respuesta_chida *= resp3;
	respuesta_chida %= modulo;
	cout<<respuesta_chida;
	return 0;
}