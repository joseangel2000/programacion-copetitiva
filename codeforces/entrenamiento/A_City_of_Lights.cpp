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

	int n, a, k, i; cin>>n>>k;
	bool arr[n + 5];
	int cont = 0, maxi = 0;

	floop(i,n) arr[i + 1] = 1;
	
	for( i = 1; i <= k ; ++i){
		cin>>a;
		for(int j = 1; j * a <= n; ++j){
			int pos = j * a;
			if(arr[pos] == false){
				cont--;
				arr[pos] = true;
				continue;
			}
			cont++;
			arr[pos] = false;
		}
		if(cont > maxi)
			maxi = cont;
	}

	cout<<maxi<<endl;
	return 0;
}