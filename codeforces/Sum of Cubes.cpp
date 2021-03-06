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
		ll x;
		cin>>x;
		ll i = 1;
		bool flag = false;
		while(true){
			if(i * i * i > x)
				break;
			ll aux = cbrt(x - pow(i, 3));
			if(pow(i, 3) + pow(aux, 3) == x && aux > 0){
				//cout<<i<<" + "<<aux<<" = "<<x<<"  ";
				flag = true;
				break;
			} 
			i++;
		}
		if(flag)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}