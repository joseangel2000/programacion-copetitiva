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
		ll p, a, b, c;
		cin>>p>>a>>b>>c;
		if(p % a == 0 || p % b == 0 || p % c == 0){
			cout<<0<<"\n";
			continue;
		}
		ll sol = a - (p % a);
		sol = min(sol, b - (p % b));
		sol = min(sol, c - (p % c));
		cout<<sol<<"\n";
	}
	return 0;
}