#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;cin>>t;
	ll a1,b1,a2,b2;
	while(t--){
		cin>>a1>>b1>>a2>>b2;
		ll len1 = max(a1,b1);
		ll len2 = max(a2,b2);
		if(len2 != len1){
			cout<<"NO\n";
			continue;
		}

		int mini1 = min(a1,b1);
		int mini2 = min(a2,b2);
		if(mini2 + mini1 != len1){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}

	return 0;
}