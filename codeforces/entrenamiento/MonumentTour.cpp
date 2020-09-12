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

	int n, m, k, x, y;
	cin>>n>>m;
	cin>>k;
	bool monument[ n + 7]; floop(i, n + 7)monument[i] = 0;
	pair<int,int> column[n + 5]; 
	floop(i , n + 5){
		column[i].first = 1000000; 
		column[i].second = -1;
	}

	vi vec;

	for(int i = 1 ; i <=k; ++i){
		cin>>x>>y;
		if(monument[x] == false){
			monument[x] = true;
			vec.pb(x);
		}
		
		if(y > column[x].second)
			column[x].second = y;
		if(y < column[x].first)
			column[x].first = y;

	}

	vi aux;
	floop(i,(int)vec.size()){
		aux.pb(column[vec[i]].first);
		aux.pb(column[vec[i]].second);
	}

	sort(aux.begin(), aux.end());

	int avenida = aux[aux.size() / 2];
	ll ans = 0;
	floop(i, vec.size()){
		int maxi = column[vec[i]].second;
		int mini = column[vec[i]].first;
		if(avenida <= maxi && avenida >= mini){
			ans  = ans + 2 * (avenida - mini) + 2 * (maxi - avenida);
			continue;
		}
		if(avenida > maxi){
			ans = ans + 2 * (avenida - mini);
			continue;
		}
		if(avenida < mini){
			ans = ans + 2 * (maxi - avenida);
			continue;
		}
	}
	ans = ans + n - 1;
	cout<<ans;
	return 0;
}