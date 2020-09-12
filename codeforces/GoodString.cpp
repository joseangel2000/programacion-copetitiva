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

	int t;cin>>t;
	
	while(t--){
		//floop(i,13)a[i] = 0;
		string s;
		cin>>s;
		int tam = s.size();
		int maxcont = 0;
		for(int i = '0'; i <= '9'; ++i){
			for(int j = '0'; j <= '9'; ++j){
				int id = 0;
				char curr = 'a';
				int cont = 0;
				while(id < tam){
					if(s[id] != i && s[id] != j){
						id++;
						continue;
					}
					if(curr == 'a' && (s[id] == i || s[id] == j)){
						curr = s[id];
						id++;
						cont++;
						continue; 
					}
					if(curr == i && s[id] == j){
						cont++;
						id++;
						curr = j;
						continue;
					}
					if(curr == j && s[id] == i){
						cont++;
						id++;
						curr = i;
						continue;
					}
					id++;
				}

				if(i != j && cont % 2 == 1)
					cont--;
				if(cont > maxcont)
					maxcont = cont;
			}
		}

		cout<<tam - maxcont<<"\n";
	}

	return 0;
}