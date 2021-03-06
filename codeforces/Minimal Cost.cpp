#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 
const int maximo = 1e6;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n, u, v;
		cin>>n>>u>>v;
		int a[n + 3];
		bool equal = true, blocked  = true;
		f(i, n){
			cin>>a[i];
			if(a[i] != a[1])
				equal = false;
			if(i > 1){
				if(abs(a[i] - a[i - 1]) > 1){
					blocked = false;
				}
			}
		}



		if(equal){
			cout<<min(u + v, 2 * v)<<"\n";
			continue;
		}
	
		if(a[n] != maximo){
			if(blocked == true){
				cout<<min(u, v)<<'\n';
				continue;
			}
			cout<<0<<"\n";
			continue;
		}



		if(a[n] == maximo){
			if(a[n - 1] == maximo){
				cout<<min(u + v, 2 * v);
				continue;
			}
			if(a[n - 1] != maximo){
				equal = blocked = true;
				ll sol = v;
				a[n] = maximo - 1;
				f(i, n){
					if(a[i] != a[1])
						equal = false;
					if(i > 1){
						if(abs(a[i] - a[i - 1]) < 1){
							blocked = false;
						}
					}
				}
				if(equal){
					cout<<(u, 3 * v)<<"\n";
					continue;
				}
				if(blocked == true){
					cout<<min(u,2 * v)<<"\n";
					continue;
				}
				cout<<"0\n";

			}
		}

		
	}
	

	return 0;
}