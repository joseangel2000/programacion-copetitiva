#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

int igual = 0, menor = 1;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;

	char mat[ n + 10] [ m + 10 ];


	//primero me dice si es igual y luego me dice en que coluna agarre la inmunidad
	pair<int,int> renglon[n + 5];
	floop(i,n+5){
		renglon[i].first = igual;
		renglon[i].second = 200;
	}


	for(int i = 1 ; i <= n; ++i)
		for(int j = 1 ; j <= m ; ++j)
			cin>>mat[i][j];

	int cont = 0;	
	for(int j = 1; j <= m; ++j ){
		for(int i = 2; i <= n ;++i){
			
			//if(j == 4)
			//	cout<<"mat[i][j] = "<<mat[i][j]<<" mat[i - 1][j] = "<<mat[i-1][j]<<endl;
			if(renglon[i].first == menor)
				continue;

			if(mat[i][j] == mat[i-1][j])
				continue;
			///asumo que hasta el momento son iguales
			if(mat[i][j] > mat[i-1][j]){
				renglon[i].first = menor;
				if(renglon[i].second > j)
					renglon[i].second = j;
				continue;
			}

			if(mat[i][j] < mat[i-1][j]){
                //cout<<"renglon =  "<<i<<" columna =  "<<j<<"  borro columna  "<<j<<endl;
                for(int k = 1 ; k <= i ;++k){
                	if(renglon[k].second == j){
                		renglon[k].first = igual;
                		renglon[k].second = 200;
                	}
                }
				cont++;
				i = n + 1;
			}


		}
	}
		
	cout<<cont;
	return 0;
}