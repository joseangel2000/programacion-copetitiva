#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 
int mat[103][103];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, limit;
	cin>>t;
	while(t--){
		cin>>n;
		if(n % 2){
			limit = (n - 1) / 2;
			for(int i = 1; i < n; ++i){
				for(int j = i + 1; j <= n; ++j){
					if(j - i <= limit) cout<<"1 ";
					if(j - i > limit) cout<<"-1 ";
				}
			}
			cout<<'\n';
			continue;
		}
		limit = n / 2;
		for(int i = 1; i < n; ++i){
			for(int j = i + 1; j <= n; ++j){
				if(j - i == limit) cout<<"0 ";
				if(j - i < limit) cout<<"1 ";
				if(j - i > limit) cout<<"-1 ";
			}
		}
		cout<<'\n';

	}	

	return 0;
}