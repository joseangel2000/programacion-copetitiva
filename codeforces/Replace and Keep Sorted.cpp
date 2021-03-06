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

	int t = 1;
	while(t--){
		int n, q, k, l, r;
		cin>>n>>q>>k;
		int a[n + 3];
		ll acumulada[n + 3];
		acumulada[0] = 0;
		f(i, n)
			cin>>a[i];
		acumulada[1] = a[2] - 2;
		for(int i = 2; i < n; ++i){
			acumulada[i]  = acumulada[i - 1] + a[i + 1] - a[i - 1] - 2; 
			//cout<<"acumulada["<<i<<"] = "<<acumulada[i]<<"\n";
		}
		
		f(i,q){
			cin>>l>>r;
			if(l == r){
				cout<<k - 1<<"\n";
				continue;
			}
			if(r == l + 1){
				cout<<a[r] - 2 + k - a[l] - 1<<"\n";
				continue;
			}
			ll sol = 0;
			sol = acumulada[r - 1] - acumulada[l];
			sol = sol + k - a[r - 1] - 1;
			sol = sol + a[l + 1] - 2;
			cout<<sol<<"\n";
			continue;
		}

	}
	return 0;
}