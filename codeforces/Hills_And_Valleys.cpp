#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
#define mp make_pair



int main(){
	int t;cin>>t;
	while(t--){
		int n, sol = 0;
		cin>>n;
		int a[n + 2];
		char state[n + 2];


		f(i,n){
			cin>>a[i];
			state[i] = 'n';	
		}
		for(int i = 2; i < n; ++i){
			
			if(a[i] < a[i - 1] && a[i] < a[i + 1])
				state[i] = 'v';
			if(a[i] > a[i - 1] && a[i] > a[i + 1])
				state[i] = 'h';
			if(state[i] != 'n'){
		
				sol++;
			}
		}

		int curr_sol = sol;
		for(int i = 2; i < n; ++i){
			int before = 0, a_before = a[i], before_1 = 3; 
			f(j,3)
				if(state[i + j - 2] != 'n'){
					
					before++;
				}
	
			bool reached = false;
			//me hago el de la izquierda
			a[i] = a[i - 1];
			if(i + 1 != n){
				if(a[i + 1] > a[i] && a[i + 1] > a[i + 2])
					before_1 = 1;
				else if(a[i + 1] < a[i] && a[i + 1] < a[i + 2])
					before_1 = 1;
				else before_1 = 0;
			}
			//me hago el de la derecha
			a[i] = a[i + 1];
			if(i - 1 != 1 && before_1 != 0){
				if(a[i - 1] > a[i] && a[i - 1] > a[i - 2])
					before_1 = 1;
				else if(a[i - 1] < a[i] && a[i - 1] < a[i - 2])
					before_1 = 1;
				else before_1 = 0;
				
			}			
			//
			if(i + 1 == n || i - 1 == 1)
			before_1 = 0;	

			a[i] = a_before;
			int k = sol - before + before_1;
			curr_sol = min(sol - before + before_1, curr_sol);
		}
		sol = curr_sol;
		cout<<sol<<"\n";

	}

	return 0;
}