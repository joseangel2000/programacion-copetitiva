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
		int n;
		cin>>n;
		int a[n + 2];
		f(i, n)
			cin>>a[i];
		ll ans = 0;
		f(i, n - 1){
			int maxi = max(a[i], a[i + 1]);
			int mini = min(a[i], a[i + 1]);
			int count = 0;
			while(true){
				if(mini * 2 >= maxi)
					break;
				mini *= 2;
				count++;
			}
			ans += count;
		}
		cout<<ans<<"\n";
	}
	return 0;
}