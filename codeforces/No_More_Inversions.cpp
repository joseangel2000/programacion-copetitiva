#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
#define mp make_pair



int main(){
	int t; cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vi b;
		int num = 2 * k - n;
		int i = 1;
		while(i < num){
			b.pb(i);
			i++;
		}
		i = k;
		while(i >= num){
			b.pb(i);
			i--;
		}
		for(i = 0; i < (int)b.size(); ++i)
			cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}