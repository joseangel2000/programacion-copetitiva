#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;cin>>t;
	
	while(t--){
		int n,x,aux;
		cin>>n>>x;
		vi pos; pos.pb(0);
		int suma = 0;
		int flag = 0;
		for(int i = 1; i <= n ; ++i){
			cin>>aux;

			if(aux % x != 0){
				flag = 1;
				suma += aux;
				pos.pb(i);
			}
		} 
		if(flag == 0){
			//cout<<"puto";
			cout<<-1<<"\n";
			continue;
		}

		if(suma % x != 0){
            //cout<<"puto";
			cout<<n<<"\n";
			continue;
		}
    	

       
		int a = pos[(int)pos.size()-1] - 1;
		int b = n - pos[1] ;
		cout<<max(a,b)<<"\n";
    	


	}

	return 0;
}