#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 





int main(){
	int t;
	cin>>t;
	while(t--){
		int w,h,n;
		//int v = 1,wv = 1, hv = 1;
		ll v = 1;
		cin>>w>>h>>n;
		while(w % 2 == 0){
			v *= 2;
			w /= 2;
		}
		while(h % 2 == 0){
			v *= 2;
			h /= 2;
		}
		if(v >= n){
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}	

	return 0;
}