#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

int n;
ll ans;
queue<int> q;
vi ts;
stack<int> dis;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin>>n;
	ll a[n + 5], b[n + 5], p[n + 5];

	for(int i = 1; i <= n; ++i){
		cin>>a[i];
		p[i] = 0;
	}
	for(int i = 1; i <= n ; ++i){
		cin>>b[i];
		p[b[i]] ++;
	}

	for(int i = 1; i <= n ; ++i)
		if(p[i] == 0)
			q.push(i);

	while(!q.empty()){
		int u = q.front(); q.pop();
		if(a[u] >= 0){
			ts.pb(u);
			ans += a[u];
			a[b[u]] += a[u];
		}
		else
			dis.push(u);
		p[b[u]]--;
		if(b[u] != -1 && p[b[u]] == 0)
			q.push(b[u]);	
	}

	while(!dis.empty()){
		ans += a[dis.top()];
		ts.pb(dis.top());
		dis.pop();
	}
	cout<<ans<<endl;
	floop(i,(int)ts.size())
		cout<<ts[i]<<" ";

	return 0;
}