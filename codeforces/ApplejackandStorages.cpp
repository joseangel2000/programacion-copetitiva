#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

const int max_size = 100010;

int n, q, aux, x;
char c;
set<int>a2, a4;
bool is_in_a2[max_size], is_in_a4[max_size];
int cant[max_size];



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	floop(i,n){
		is_in_a4[i + 1] = 0;
		is_in_a2[i + 1] = 0;
		cant[i + 1] = 0;
	}
	floop(i,n){
		cin>>aux;
		cant[aux]++;
		if(cant[aux] == 4){
			is_in_a4[aux] = true;
			a4.insert(aux);
		}
		if(cant[aux] == 2){
			is_in_a2[aux] == true;
			a2.insert(aux);
		}
	}

	cin>>q;
	while(q--){
		cin>>c>>x;
		if(c == '+'){
			cant[x]++;
			if(cant[x] == 4){
				is_in_a4[x] = true;
				a4.insert(x);
			}
			if(cant[x] == 2){
				is_in_a2[x] = true;
				a2.insert(x);
			}
		}
		if(c == '-'){
			cant[x]--;
			if(cant[x] == 1){
				auto it = a2.find(x);
				a2.erase(it);
				is_in_a2[x] = false;
			}
			if(cant[x] == 3){
				auto it = a4.find(x);
				a4.erase(it);
				is_in_a4[x] = false;
			}
		}

		if(a4.size() >= 2){
			cout<<"YES\n";
			continue;
		}
		if(a4.size() == 0){
			cout<<"NO\n";
			continue;
		}
		if(a4.size() == 1){

			auto it = a4.begin();
			int con = *it;
			int contenido = cant[con];

			/*cout<<"ahorita cant[1] -> "<<cant[1]<<" cant[2] ->"<<cant[2]<<" ";
			cout<<"con = "<<con<<" contenido = "<<contenido<<" a2.size = "<<a2.size()<<" ";
				*/
			if(contenido >= 8){
				cout<<"YES\n";
				continue;
			}
			if(contenido >= 6 && a2.size() >= 2){
				cout<<"YES\n";
				continue;
			}
			if(contenido >= 4 && a2.size() >= 3){
				cout<<"YES\n";
				continue;
			}
			cout<<"NO\n";
		}
	}


	return 0;
}