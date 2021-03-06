#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
const int inf = 2e5 + 10;
const int min_inf = -200010;

vi a; // el arreglo que lo dira todo 

class segment_tree{
	public:
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
				build_max(node * 2, l, (r + l) / 2);
				build_max(node * 2 + 1, (r + l) / 2 + 1, r);
				int a1 = st_max[node * 2];
				int a2 = st_max[node * 2 + 1];
				st_max[node] = max(a1, a2); 
			}
			return;
		}	
		          // L y R son los rangos de verdad e i y j son los de la funcion
		int rminq(int node, int L, int R, int i, int j){
			if(L > j || R < i)
				return inf;
			if(L <= i && R >= j)
				return st_min[node];
			int a1 = rminq(node * 2, L, R, i, (i + j) / 2);
			int a2 = rminq(node * 2 + 1, L , R, (i + j) / 2 + 1, j);
			if(a1 == inf) return a2;
			if(a2 == inf) return a1;
			return min(a1, a2);
		}
		int rmaxq(int node, int L, int R, int i, int j){
			if(L > j || R < i)
				return inf;
			if(L <= i && R >= j)
				return st_max[node];
			int a1 = rmaxq(node * 2, L, R, i, (i + j) / 2);
			int a2 = rmaxq(node * 2 + 1, L , R, (i + j) / 2 + 1, j);
			if(a1 == inf) return a2;
			if(a2 == inf) return a1;
			return max(a1, a2);
		}

		segment_tree(int n){
			st_min.resize(4 * n + 2);
			st_max.resize(4 * n + 2);
			build_min(1, 0, n);
			build_max(1, 0, n);
		}

};


int main(){
	int t; cin>>t;
	int n, m, x, y, min1, min2, max1, max2;
	string s;	
	while(t--){
		a.clear();
		s.clear();
		cin>>n>>m;
		cin>>s;
		a.pb(0);
		f(i, n){
			if(s[i - 1] == '+')
				a.pb(a[i - 1] + 1);
			else 
				a.pb(a[i - 1] - 1);
		}

		segment_tree st1(n);
		
		/*cout<<"a =  ";
		f(i, a.size())
			cout<<a[i - 1]<<" ";
		cout<<"\n\n\n\n";
		/*cout<<"st_max =  \n";
		f(i, 4*n + 1){
			cout<<i<<" "<<st1.st_max[i]<<"\n";
		}
		//cout<<"la rminq de 5 a 7 es "<<st1.rminq(1, 5,7,5,7);
		cout<<"\n\n\n\n\n\n";*/
		f(i,m){
			cin>>x>>y;
			min1 = st1.rminq(1, 0, x - 1, 0, n);
			max1 = st1.rmaxq(1, 0, x - 1, 0, n);
			min2 = st1.rminq(1, y + 1, n, 0, n);
			max2 = st1.rmaxq(1, y + 1, n, 0, n);
			min2 = min2 - a[y] + a[x - 1];
			max2 = max2 - a[y] + a[x - 1];

			if(x == 1){
				min1 = 0;
				max1 = 0;
			}
			if(y == n){
				min2 = inf;
				max2 = (-1)* min2;
			}
			if(x == 1 && y == n)
				min2 = max2 = min1 = max1 = 0;
			min1 = min(min1, min2);
			max1 = max(max1, max2);

			//if(x == 1 && y == n)
			//	max1 = min1 = 0;

			cout<<max1 - min1 + 1<<"\n";
		}

	}

	return 0;
}