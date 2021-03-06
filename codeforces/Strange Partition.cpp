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
		int n, x; 
		cin>>n>>x;
		ll mini = 0, aux, maxi = 0;
		f(i, n){
			cin>>aux;
			mini += aux;
			if(aux % x == 0){
				maxi = maxi + aux/x;
				continue;
			}
			maxi = maxi + aux / x + 1;
		}
		mini /= x;
		cout<<mini<<" "<<maxi<<'\n';
	}	
	

	return 0;
}