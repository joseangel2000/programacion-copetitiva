#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,aux,  unos = 0, dos = 0;
		cin>>n;
		f(i, n){
			cin>>aux;
			if(aux == 1)
				unos++;
			else dos++;
		}
		int suma = unos + 2* dos;
		if(suma % 2){
			cout<<"NO\n";
			continue;
		}
		if((suma / 2) % 2 && unos == 0){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		

	}	

	return 0;
}