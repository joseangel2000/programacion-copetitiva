#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 
const int inf = INT_MAX - 1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	bool got_it = false;
	bool visited[n + 2];
	for(int i = 0; i < n + 2; ++i) visited[i] = false;
	int a[n + 2];
	visited[0] = visited[n + 1] = true;
	a[0] = a[n + 1] = inf;
	int l = 1, r = n, mid, sol;
	while(true){
		mid = (l + r) / 2;
		if(!visited[mid - 1]){
			cout<<"? "<<mid - 1<<'\n';
			cout.flush();
			cin>>a[mid - 1];
		}
		if(!visited[mid + 1]){
			cout<<"? "<<mid + 1<<'\n';
			cout.flush();
			cin>>a[mid + 1];
		}
		if(!visited[mid]){
			cout<<"? "<<mid<<'\n';
			cout.flush();
			cin>>a[mid];
		}

		if(a[mid - 1] > a[mid] && a[mid] < a[mid + 1]){
			sol = mid;
			break;
		}
		if(a[mid - 1] < a[mid]){
			r = mid - 1;
			continue;
		}
		if(a[mid + 1] < a[mid]){
			l = mid + 1;
			continue;
		}
	}
	cout<<"! "<<sol;
	cout.flush();	

	return 0;
}