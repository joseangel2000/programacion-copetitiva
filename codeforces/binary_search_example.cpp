#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define max_size 200010

int n,k;
int a[max_size];
//int lo, hi;

bool check(int x, int current){
	int ans = 0;
	for(int i = 1; i <= n ; ++i){
		
		if(!current){
			ans++;
			current = 1;
			continue;
		}
		else{
			if(a[i] <= x){
				ans++;
				current = 0;
				continue;
			}
		}

	}
	return ans >= k;
}

int binary_search(int lo, int hi){

	while(hi > lo){
		int mid = (hi + lo) / 2;

		if(check(mid,0) || check(mid,1))
			hi = mid;
		
		else
			lo = mid + 1;
	}

	return lo;
}

int main(){
	cin>>n>>k;
	int maxi = 0;
	for(int i = 1; i <= n ;++i){
		cin>>a[i];
		if(a[i] > maxi)
			maxi = a[i];
	}
	//for(int i = 1; i <= n ;++i)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	//lo = 1; hi = 1;
	//sort(a, a + n);

	int ans = binary_search(1,maxi);

	cout<<ans<<"\n";

	return 0;
}