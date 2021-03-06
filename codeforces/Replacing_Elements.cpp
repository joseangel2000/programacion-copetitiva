#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
const int inf = 1e5 + 10;
const int min_inf = -100010;

vi a; // el arreglo que lo dira todo 

class segment_tree{
	private:
		vi st_max;
		vi st_min;

		void build_min(int node, int l, int r){
			if(l == r)
				st_min[node] = a[l];
			else{
				build_min(node * 2, l, (r + l) / 2);
				build_min(node * 2 + 1, (r + l) / 2 + 1, r);
				int a1 = st_min[node * 2];
				int a2 = st_min[node * 2 + 1];
				st_min[node] = min(a1, a2); 
			}
			return;
		}	
		void build_max(int node, int l, int r){
			if(l == r)
				st_max[node] = a[l];
			else{
				build_min(node * 2, l, (r + l) / 2);
				build_min(node * 2 + 1, (r + l) / 2 + 1, r);
				int a1 = st_max[node * 2];
				int a2 = st_max[node * 2 + 1];
				st_max[node] = max(a1, a2); 
			}
			return;
		}	          // L y R son los rangos de verdad e i y j son los de la funcion
		int rminq(int node, int L, int R, int i, int j){
			if(L > j || )
		}

	public:
		segment_tree(int n){
			st.resize(4 * n + 2);
			build_min(1, 0, n);
			build_max(1, 0, n);
		}

};


int main(){
	int t, n, d, aux; cin>>t;	
	while(t--){
		cin>>n>>d;
		vi arr;
		for(int i = 1; i <= n; ++i){
			cin>>aux;
			arr.pb(aux);
		}
		sort(arr.begin(), arr.end());
		int suma = arr[0] + arr[1];
		if(suma <= d || arr[arr.size() - 1] <= d)
			cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}