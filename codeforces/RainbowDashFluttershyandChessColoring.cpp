#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		if(n % 2 == 1){
			cout<<(n + 1) / 2<<"\n";
			continue; 
		}
		cout<<n / 2 + 1<<"\n";
	}

	return 0;
}