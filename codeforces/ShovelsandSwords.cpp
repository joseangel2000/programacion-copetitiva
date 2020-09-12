#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,a,b,idx,n,x,m;cin>>t;
	
	while(t--){
		a = n; b = 0;
		cin>>a>>x>>m;
        int arr[m+1][2];
		floop(i,m)cin>>arr[i][0]>>arr[i][1];
		int idx = 0;
		frep(i,0,m-1){
			if(arr[i][0] <= x && arr[i][1] >= x){
				idx = i;
				a = arr[i][0]; b = arr[i][1];
				break;
			}
		}

		frep(i,idx + 1, m-1){
			if(arr[i][0] > b || arr[i][1] < a)
				continue;
			if(arr[i][0] < a) a = arr[i][0];
			if(arr[i][1] > b) b = arr[i][1]; 
		}
		cout<<(b - a + 1)<<"\n";
        

	}

	return 0;
}