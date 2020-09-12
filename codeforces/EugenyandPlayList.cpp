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

	int n,m,v,c,t; cin>>n>>m;
	vi vec;
	vec.pb(0);
	for(int i = 1 ; i <=  n ; ++i){
		cin>>c>>t;
		int aux = vec[i - 1] + c * t;
		vec.pb(aux);
	}
	vec.pb(1000000005);

	int idx = 0;
	for(int i = 0 ; i < m ; ++i){
		cin>>v;
		while(vec[idx] < v ){
			idx++;
		}
		cout<<idx<<"\n";
	}

	return 0;
}