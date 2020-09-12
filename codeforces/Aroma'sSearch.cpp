#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair
const long long int max_distance = 1000000000000000000;

ll distancia(set<pair<ll,ll> >::iterator a, pair<ll,ll> b){
	ll ans1, ans2;
	ans1 = a->first - b.first;
	if(ans1 < 0) ans1 *= -1;
	ans2 = a->second - b.second;
	if(ans2 < 0) ans2 *= -1;
	return ans1 + ans2; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll x0, y0, ax, ay, bx, by, xs, ys, t;
	pair<ll,ll> current;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	
	current.first = xs; current.second = ys;
	//nodes.pb(mp(x0, y0));
	set<pair<ll,ll> > seta;
	while(x0 > 0 && y0 > 0  ){
		seta.insert(mp(x0,y0));
		x0 *= ax; x0 += bx;
		y0 *= ay; y0 += by;
	}

	int cont = 0;
	while(true){
		set<pair<ll,ll> >::iterator idx;
		ll currdist = max_distance;
		for(set<pair<ll,ll> >::iterator it = seta.begin(); it != seta.end(); ++it){
			if(distancia(it, current) < currdist){
				currdist = distancia(it, current);
				idx = it;
			}
		}

	
		if(t - currdist < 0)
			break;
		if(t - currdist >= 0){
			t -= currdist;
			cont++;
			current.first = idx->first;
			current.second = idx->second;
			seta.erase(idx);
		}

	}

	cout<<cont;


	return 0;
}