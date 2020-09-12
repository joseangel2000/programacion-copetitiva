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

	ll n;
	long double aux = 1.5;
	//ll aux1 = 1;
	cin>>n;

	if(n == 1){
		cout<<1;
		return 0;
	}
	if(n == 2){
		cout<<2;
		return 0;
	}


	ll idx1 = 1, idx2 = 3;
	ll raiz = 1;
	ll cont = 0 ;
	while(idx1 <= n){
		cont = cont + (raiz * (idx2 - idx1));

		aux += 1;
		raiz++;

		idx1 = idx2; 
		idx2 = (ll)(aux * aux) + 1;

		if(idx2 > n)
			idx2 = n + 1;

	}

	cout<<cont;
	return 0;
}