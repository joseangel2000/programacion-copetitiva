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

	int N,n;
	pair<char, int> aux;
	string s;
	cin>>N;
	while(N){
		int pile1 = 0, pile2 = 0 ;
		vector<pair<char,int> > vec;
		for(int i = 1; i <= N; ++i){
			cin>>s>>n;
			//cout<<s<<n<<endl;
			aux.first = s[0];
			aux.second = n;
			vec.pb(aux);
		}
		for(int i = 0; i < N; ++i){
			char letra = vec[i].first;
			int numero = vec[i].second;
			int currnum = numero;

			if(letra == 'D'){
				pile2 += numero;
				cout<<"DROP 2 "<<numero<<"\n";
				continue;
			}
			
			if(pile1 >= numero){
				pile1 -= numero;
				cout<<"TAKE 1 "<<numero<<"\n";
				continue;
			}		

			//MOVE 2->1 100
			if(pile1 > 0)cout<<"TAKE 1 "<<pile1<<"\n";
			numero -= pile1;
			pile1 = 0;
			cout<<"MOVE 2->1 "<<pile2<<"\n";
			pile1 = pile2;
			pile2 = 0;
			cout<<"TAKE 1 "<<numero<<"\n";
			pile1 -= numero;
		}
		cout<<"\n";
		cin>>N;
			
	}

	return 0;
}