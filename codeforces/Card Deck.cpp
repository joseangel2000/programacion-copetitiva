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
		//cout<<"hola\n";
		int n;
		cin>>n;
		int p[n + 2];
		vi sol;
		bool chosen[n + 2];


		f(i, n){
			cin>>p[i];
			chosen[p[i]] = false;
		}

		int maxi = n;
		int indice = n;
		int top = n ;
		while(true){
			//cout<<"hola\n";
			while(true){
				chosen[p[indice]] = true;
				if(p[indice] == maxi)
					break;
				indice--;
			}
			for(int i = indice; i <= top; ++i)
				sol.pb(p[i]);

			top = indice - 1;
			indice--;

			if(indice <= 0)
				break;
			
			while(chosen[maxi]){
				maxi--;
			}
		}

		f(i,n){
			cout<<sol[i - 1]<<" ";
		}
		cout<<"\n";

	}
	return 0;
}