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
	
	int t, type, k;
	
	
	int n, unos = 0,ceros = 0;
	cin>>n>>t;
	int a[n + 2];
	f(i,n ){
		cin>>a[i];
		if(a[i] == 0)
			ceros++;
		else
			unos++;
	}
	f(i, t){
		cin>>type>>k;
		if(type == 1){
			if(a[k] == 0)
				ceros -= 1, unos += 1;
			else 
				unos -= 1, ceros += 1;
			a[k] = 1 -  a[k];
		}
		if(type == 2){
			if(k > unos)
				cout<<"0\n";
			else
				cout<<1<<'\n';
		}
	}

	
	

	return 0;
}