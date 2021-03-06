#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair


ll gauss(ll a){
	return (a * (a + 1) )/ 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; 
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		string respuesta;
		
		ll rango_gauss = sqrt(k * 2) - 1;
		while(k > gauss(rango_gauss))
			rango_gauss++;

		k = k - gauss(rango_gauss - 1);
		
		ll pos1 = n - 1 + 1 - k;
		ll pos2 = n - 1 - rango_gauss;


		for(int j = 0 ; j < n ;++j){
			if(j == pos2 || j == pos1){
				cout<<"b";
				continue;
			}
			cout<<"a";
		}
		cout<<"\n";

	}

	return 0;
}