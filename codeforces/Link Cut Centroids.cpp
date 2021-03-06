#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 
const int max_tam = 1e5 + 2;
vi adlist[max_tam];
int fa[max_tam], size[max_tam];
bool visited[max_tam];
int cent1, cent2, n, minimo = INT_MAX - 1, x, y;


void find_centroids_dfs(int u, int f){
	fa[u] = f; 
	size[u] = 1;
	int maxi = 0;
	for(int i = 0; i < adlist[u].size(); ++i){
		int v = adlist[u][i];
		if(v == fa[u])
			continue;
		find_centroids_dfs(v, u);
		size[u] += size[v];
		maxi = max(maxi, size[v]);
	}
	maxi = max(maxi, n - size[u]);
	if(maxi < minimo){ 
		cent1 = u;
		cent2 = 0;
		minimo = maxi;
	}
	else if(maxi == minimo){
		cent2 = u;
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	visited[0] = false;
	int t;
	cin>>t;
	while(t--){
		cin>>n;  minimo = INT_MAX - 1;  
		f(i,n) adlist[i].clear(), fa[i] = 0, visited[i] = false;
		f(i, n - 1){
			cin>>x>>y;
			adlist[x].pb(y);
			adlist[y].pb(x);
		}
		find_centroids_dfs(1,0);
		//cout<<"los centroides son "<<cent1<<"   "<<cent2<<endl<<endl;

		if(cent2 == 0){
			cout<<1<<" "<<adlist[1][0]<<"\n"<<1<<" "<<adlist[1][0]<<"\n";
			continue;
		}

		stack<int> s;
		s.push(cent2);
		visited[cent2] = true;
		while(!s.empty()){
			int u = s.top();
			s.pop();
			for(int i = 0; i < (int)adlist[u].size(); ++i){
				int v = adlist[u][i];
				if(visited[v] == true || v == cent1)
					continue;
				visited[v] = true;
				s.push(v);
				if(adlist[v].size() == 1){
					x = u, y = v;
					break;
				}
			}
		}
		cout<<x<<" "<<y<<'\n';
		cout<<cent1<<" "<<y<<'\n';
	}
	

	return 0;
}