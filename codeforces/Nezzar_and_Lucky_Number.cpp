#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
const int max_tam = 1e5 + 3;

int d,a;

bool intento(){
	int aux = a;
	while(true){
		if(aux < 0)
			return false;
		if(aux % 10 == d)
			return true;
		aux -= d;
	}
}

void check(){
	if(a >= 10*d){
		cout<<"YES\n";
		return ;
	}
	
	if(intento() == true){
		cout<<"YES\n";
		return ;
	}
	cout<<"NO\n";
	return ;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int q; 
		cin>>q>>d;
		for(int i = 1; i <= q; ++i){
			cin>>a;
			check();
		}		
	}
	return 0;
}