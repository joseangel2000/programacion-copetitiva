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
		int n, number, cont = 0;
		cin>>n;
		vi vec(n);
		f(i,n)
			cin>>vec[i - 1];
			
		
		sort(vec.begin(), vec.end());
		/*f(i,n){
			cout<<vec[i - 1]<<"  ";
		}
		cout<<endl;*/
		vi C;
		vi C_1;
		map<int,int> mapa;
		for(int i = 0; i < n; ++i){		
			if(i == 0){
				number = vec[0];
				cont = 1;
				continue;
			}
			if(vec[i] == number)
				cont++;
			if(vec[i] != number){
				if(mapa[cont] == 0){
					C.pb(cont);
					mapa[cont]++;
				}
				C_1.pb(cont);
				cont = 1;
				number = vec[i];
			}
		}	
		C_1.pb(cont);
		if(mapa[cont] == 0){
			C.pb(cont);
			mapa[cont]++;
		}


		ll sol = 1e18;
		ll posible_sol = 0;
		for(int i = 0; i < (int)C.size(); ++i){
			//cout<<"c["<<i<<"] = "<<C[i]<<" \n";
			posible_sol = 0;
			for(int j = 0; j < (int)C_1.size(); ++j){
				if(C_1[j] < C[i])
					posible_sol += C_1[j];
				if(C_1[j] >= C[i])
					posible_sol = posible_sol + C_1[j] - C[i];
			}
			sol = min(sol, posible_sol);
		}
		cout<<sol<<"\n";
	}	

	return 0;
}