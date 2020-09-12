#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back

vi vec;
int check[107];

void colocar(int posicion, int numero){
	int tam = (int)vec.size();
	vec.pb(vec[tam-1]);
	for(int i = tam ; i > posicion ; --i)
		vec[i] = vec[i-1];
	vec[posicion] = numero;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, k, aux, diferent;
	cin>>t;
	
	while(t--){
		floop(i,105) check[i] = 0;
		diferent = 0;
		cin>>n>>k;
		vec.clear();
		floop(i,n){
			cin>>aux;
			if(check[aux] == 0) diferent++ ; 
			check[aux] = 1;
			vec.pb(aux);
		}

		if(diferent > k){
			cout<<-1<<endl;
			continue;
		}

		frep(i,k,(int)vec.size()-1){
			if(vec[i] == vec[i-k]) continue;
			colocar(i,vec[i-k]);
		}

		cout<<(int)vec.size()<<endl;
		floop(i,(int)vec.size()) cout<<vec[i]<<" ";
		cout<<endl;
	}

	return 0;
}