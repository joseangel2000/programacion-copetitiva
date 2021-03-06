#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 





int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll a[n + 2];
		f(i, n)
			cin>>a[i];
		ll max = 0;
		for(int i = n; i >= 1; --i){
			if(i + a[i] <= n)
				a[i] = a[i] + a[i + a[i]];
			if(a[i] > max)
					max = a[i];
		}
		cout<<max<<"\n";
	}	

	return 0;
}