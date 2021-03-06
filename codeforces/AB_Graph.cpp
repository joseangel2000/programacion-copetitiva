#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
const int max_tam = 1e5 + 3;



int main(){
	int t; cin>>t;
	while(t--){
		int n, m;
		bool flag = true;

		cin>>n>>m;
		string edges[n + 2];

		if(n >= 3 || m % 2 == 1){
			cout<<"YES\n";		
		}

		

		for(int i = 1; i <= n; ++i)
				cin>>edges[i];
	
		if(m % 2 == 1){
			//cout<<"obvi m = "<<m<<endl;
			for(int i = 1; i <= m + 1; ++i){
				if(i % 2 == 1)
					cout<<1<<" ";
				else cout<<2<<" ";
			}
			cout<<endl;
			continue;
		}


		if(n == 2){
			if(edges[1][1] == edges[2][0])
				cout<<"YES\n";
			else{
				cout<<"NO\n";
				continue;
			}

		}

		int x = 0,y = 0,z = 0;
		for(int i = 1; i <= n; ++i){
			if(x != 0)
				break;
			for(int j = 1; j <= n; ++j){	
				if(edges[i][j - 1] == edges[j][i - 1] && i != j){
					x = i; 
					y = j;
					break;
				}

			}	
		}

		if(x != 0){
			//cout<<"x = "<<x<<"  y = "<<y<<endl;
			for(int i = 0; i < m + 1; ++i){
				if(i % 2 == 0)
					cout<<x<<" ";
				if(i % 2 == 1)
					cout<<y<<" ";
			}
			cout<<"\n";
			continue;
		}

		bool pos[4];
		pos[1] = pos[2] = pos[3] = false;
		for(int id_1 = 1; id_1 <= 3; ++id_1){
			if(x != 0)
				break;
			bool ab[3]; 
			ab[1] = false; ab[2] = false; 
			
			for(int id_2 = 1;id_2 <= 3; ++id_2){
				if(id_1 == id_2)
					continue;
				if(edges[id_1][id_2 - 1] == 'a')
					ab[1] = true;
				if(edges[id_1][id_2 - 1] == 'b')
					ab[2] = true;
				if(ab[1] == true && ab[2] == true){
					y = id_1;
					x = id_2;
					pos[x] = true;
					pos[y] = true;
					break;
				}
			}
		}

		for(int i = 1; i <= 3; ++i)
			if(pos[i] == false)
				z = i;

		if(m % 2 == 1){
			for(int i = 0; i <= m; ++i){
				if(i % 2 == 0)
					cout<<x<<" ";
				if(i % 2 == 1)
					cout<<y<<" ";
			}
			cout<<"\n";
			continue;	
		}
		if((m/2) % 2 == 1){
			for(int i = 1; i <= m + 1; ++i){
				if(i % 2 == 0){
					cout<<y<<" ";
					continue;
				}
				if(i % 4 == 1){
					cout<<x<<" ";
					continue;
				}
				cout<<z<<" ";
			}
			cout<<"\n";
			continue;
		}
		for(int i = 1; i <= m + 1; ++i){
			if(i % 2 == 1){
				cout<<y<<" ";
				continue;
			}
			if(i % 4 == 2){
				cout<<z<<" ";
				continue;
			}
			cout<<x<<" "; 
		}
		cout<<"\n";

	}
	return 0;
}