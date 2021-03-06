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

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		s.pb('R');
		int maxi = 0;
		int aux = 0;
		for(int  i = 0 ; i < s.size(); ++i){
			if(s[i] == 'L'){
				aux++;
				if(s[i + 1] == 'R')
					maxi = max(maxi, aux); 
			}
			if(s[i] =='R')
				aux = 0;
		}
		cout<<maxi + 1<<"\n";
	}
	

	return 0;
}