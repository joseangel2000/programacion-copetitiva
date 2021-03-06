#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 


int solve(int a, int b){
	int a_1 = a,b_1 = b;
	int sol = INT_MAX - 1, posible_sol = 0;
	for(int i = 0; i < 20; ++i){
		a_1 = a;
		b_1 = b;
		posible_sol = 0;
		if(b == 1){
			b_1++;
			posible_sol = 1;
		}
		b_1 += i;
		posible_sol += i;
		while(a_1 > 0){
			a_1 /= b_1;
			posible_sol++;
		}
		sol = min(sol, posible_sol);
	}
	return sol;

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<solve(a,b)<<"\n";

	}
	return 0;
}