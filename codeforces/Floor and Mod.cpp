#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	for(ll i = 1; i*i < x; i++)ans+=max(min(y,x/i-1)-i,0LL);
	cout << ans << endl;
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}