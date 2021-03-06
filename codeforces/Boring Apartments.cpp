#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 

int gauss(int k){
	return (k*(k + 1)) / 2;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string x;
		cin>>x;
		int digitos = x.size();
		int num = x[0]-'0';
		int sol = (num - 1) * 10;
		sol = sol + gauss(digitos);
		cout<<sol<<"\n";
	}
	

	return 0;
}