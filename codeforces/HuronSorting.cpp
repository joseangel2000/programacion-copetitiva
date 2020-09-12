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

	int t;cin>>t;
		int n,k,aux,maxi = 0,des = 0;
	while(t--){

		des = 0;
		cin>>n>>k;
		int arr[n+5];
		
		vi vec;
		floop(i,n){
			cin>>arr[i + 1];
			if(arr[i + 1] != i + 1){
				vec.pb(i + 1);
				des++;
			}
					
		}
		if(des == 0){
			cout<<"Yes\n";
			continue;
		}

		if(k == 0 && des > 0){
			cout<<"No\n";
			continue;
		}

		if(k == 1){
			if(des == 2){
				cout<<"Yes\n";
				continue;
			}
			cout<<"No\n";
		}

		if(k == 2){
			if(des <= 3){
				cout<<"Yes\n";
				continue;
			}
			if(des == 4){
				int a1 = arr[vec[0]], a2 = arr[vec[1]], a3 = arr[vec[2]], a4 = arr[vec[3]];
				if(arr[a1] == a2 && arr[a2] == a1){
					cout<<"Yes\n";
					continue;
				}
				if(arr[a1] == a3 && arr[a3] == a1){
					cout<<"Yes\n";
					continue;
				}
				if(arr[a1] == a4 && arr[a4] == a1){
					cout<<"Yes\n";
					continue;
				}
				cout<<"No\n";
			}
			if(des > 4){
				cout<<"No\n";
			}
		}

		if(k > 2){
			cout<<"Yes\n";
		}

	}

	return 0;
}