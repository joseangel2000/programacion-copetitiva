#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

ll r, g, b, w;
ll ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		cin>>r>>g>>b>>w;
		int impares = 0;
		int mayores = 0;
		if(r % 2 == 1)
			impares++;
		if(g % 2 == 1)
			impares++;
		if(b % 2 == 1)
			impares++;if(w % 2 == 1)impares++;

		if(r > 0) mayores++; if(g > 0) mayores++; if(b > 0) mayores++; if(w > 0) mayores++;

		if(impares == 2){
			cout<<"No\n";
			continue;
		}
		if(r == 0 || b == 0 || g == 0){
			if(impares != 1 && impares != 0){
				cout<<"No\n";
				continue;
			}
		}
		
		cout<<"Yes\n";
	}

	return 0;
}