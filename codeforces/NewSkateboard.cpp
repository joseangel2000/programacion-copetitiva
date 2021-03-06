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

	string s;
	cin>>s;

	int n = s.size();

	vi pos;

	ll digitos = 0;
	for(int i = 0 ; i < n; ++i)
		if((s[i] - '0') % 4 == 0)
			digitos++;
	for(int i = 1; i < n ; ++i){
		int num = 10 * (s[i-1] - '0') + (s[i] - '0');
		if(num % 4 == 0)
			pos.pb(i);

	}

	ll respuesta = digitos;
	for(int i = 0 ; i < pos.size(); ++i){
		respuesta += pos[i];
	}

	cout<<respuesta;


	return 0;
}