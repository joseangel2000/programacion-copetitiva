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
		int n, mini = INT_MAX - 1;
		cin>>n;
		int a[n + 2];
		f(i,n){
			cin>>a[i];
			mini = min(mini, a[i]);
		}
		int sol = 0;
		f(i, n)
			if(a[i] > mini)
				sol++;
		cout<<sol<<'\n';
	}	

	return 0;
}