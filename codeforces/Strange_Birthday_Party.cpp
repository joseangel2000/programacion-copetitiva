#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
#define mp make_pair



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vi k(n),c(m);
		f(i, n)
			cin>>k[i - 1];
		f(i, m)
			cin>>c[i - 1];
		sort(k.begin(), k.end(), greater<int>());

		ll ans = 0;
		int lim = min(m, n);

		for(int i = 0; i < lim; ++i){
			//cout<<"k = "<<k[i];
			//cout<<"   c = "<<c[i]<<"";
			ll aux = min(c[i], c[k[i] - 1]);
			//cout<<"   voy a sumar "<<aux<<"\n\n";
			ans += aux;
		}
		for(int i = lim; i < n; ++i)
			ans += c[k[i] - 1];
		cout<<ans<<"\n";

	}

	return 0;
}