#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 


ll gauss(ll n){
	return (n * (n + 1) / 2);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		
		ll sum = 0, aux, n;
		cin>>n;
		int h[n + 2];
		bool flag = true;
		f(i, n){
			cin>>aux;
			h[i] = aux;
			sum += aux;
			if(flag && sum < gauss(i - 1)){
				cout<<"NO\n";
				flag = false;
			}
		}
		if(flag)
			cout<<"YES\n";

	}
	return 0;
		
}