#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define iter set<int>::iterator
int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n; cin>>t;
	while(t--){
		cin>>n;
		int arr[ n + 10], mini;
		int aux[n + 10];
		vi vec;
		floop(i, n){
			cin>>arr[i + 1];
			aux[i + 1]  = arr[i + 1];
		}
		sort(aux + 1, aux + n + 1);
		mini = aux[1];
		int flag = 1;
		floop(i, n){
			if(arr[i + 1] != aux[i + 1]){
				vec.pb(i + 1);	
				if(gcd(aux[i + 1], mini) != mini){
					cout<<"NO\n";
					flag = 0;
				}
			}
			if(!flag)
				break;
		}
		if(!flag) continue;
		cout<<"YES\n";


	}

	return 0;
}