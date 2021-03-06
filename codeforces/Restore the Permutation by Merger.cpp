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
		int n, aux;
		cin>>n;
		bool chosen[n + 2];
		f(i,n)
			chosen[i] = false;
		vi sol;
		f(i,2 * n){
			cin>>aux;
			if(chosen[aux])
				continue;
			chosen[aux] = true;
			sol.pb(aux);
		}
		f(i,n)
			cout<<sol[i - 1]<<" ";
		cout<<"\n";

	}
	
	

	return 0;
}