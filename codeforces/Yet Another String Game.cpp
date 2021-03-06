#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i = 0; i < s.size(); ++i){
			if(i % 2 == 1){
				if(s[i] == 'z'){
					s[i] = 'y';
				}
				else{
					s[i] = 'z';
				}
			}
			if(i % 2 == 0){
				 if(s[i] == 'a'){
				 	s[i] = 'b';
				 }
				 else{ 
				 	s[i] = 'a';
				 }
			}
			
		}
		cout<<s<<endl;
	}

	return 0;
}