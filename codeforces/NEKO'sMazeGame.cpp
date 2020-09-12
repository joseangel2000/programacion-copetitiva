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
	int n,q,c,f;
	cin>>n>>q;

	bool mat[3][n + 5];
	frep(i,1,2)
		frep(j,1,n)
			mat[i][j] = true;

	int conected = n - 1;
	int conection[n + 5]; floop(i,n)conection[i] = 1;	
	while(q--){
		cin>>c>>f;
		int flag1 = 0;
		if(mat[c][f] == true){mat[c][f] = false; flag1 = 1;}
		if(flag1 == 0)
			mat[c][f] = true;

		if(f < n){//si no soy el tope
			int flag = 0;
			if(conection[f] == 0){
				if((mat[1][f] == 1 && mat[1][f + 1] == 1) || (mat[2][f] == 1 && mat[2][f + 1] == 1)){
					conection[f] = 1;
					conected++;
					flag = 1;
				}

			}
			if(conection[f] == 1 && flag == 0){
				if(!(mat[1][f] == 1 && mat[1][f + 1] == 1) && !(mat[2][f] == 1 && mat[2][f + 1] == 1)){
					conection[f] = 0;
					conected--;
				}
			}
		}
		

		if(f > 1){///si no soy el de hasta abajo
			int flag = 0;
			if(conection[f - 1] == 0){
				if((mat[1][f - 1] == true && mat[1][f] == true) || (mat[2][f-1] == true && mat[2][f] == true)){
					conection[f-1] = 1;
					conected++;
					flag = 1;
				}
			}
			if(conection[f - 1] == 1 && flag == 0){
				if(!(mat[1][f - 1] == true && mat[1][f] == true) && !(mat[2][f-1] == true && mat[2][f] == true)){
					conection[f-1] = 0;
					conected--;
				}
			}

		}
		if(conected == n-1){
			cout<<"Yes\n";
			continue;
		}
		cout<<"No\n";
	}


	return 0;
}