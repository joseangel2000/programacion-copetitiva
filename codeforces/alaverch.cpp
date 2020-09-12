#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair


int n;
string s;




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	string aux;
	vector<string> vec;

	for(int i = 0; i < n; ++i){
		cin>>s;
		sort(s.begin(),s.end(), greater<int>());
		aux = s;
		vec.pb(aux);
	}
	
	sort(vec.begin(),vec.end()/*, greater<int>()*/);
	
	for(int i = (int)vec.size() - 1 ; i >= 0 ; --i){
		cout<<vec[i];
	}
	return 0;
}
