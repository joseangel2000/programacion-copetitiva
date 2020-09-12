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
		ll sum = 0;
		int n,k,aux;
		cin>>n>>k;

		vi v1,v2;

		int arr[ n + 5];
		for(int i = 1; i <= n ;++i)
			cin>>arr[i];	
		int w[ k + 5 ];
		floop(i,k){
			cin>>aux;
			if(aux == 1){
				v1.pb(1);
				continue;
			}
			v2.pb(aux);
		}
		sort(arr + 1, arr + n + 1);
		sort(v2.begin(), v2.end(), greater<int>());
		int idx1 = 1, idx2 = n; 

				

		for(int i = 0; i < (int)v1.size(); ++i){
				
				sum += arr[idx2];
				sum += arr[idx2];
				idx2--;
				//cout<<sum<<" \n";
				continue;

		}
		//cout<<sum<<"\n";
		for(int i = 0; i < (int)v2.size() ; ++i){
			//cout<<"v2 - "<<v2[i]<<" idx1  = "<<idx1<<endl;
			int cont = 2;
			sum += arr[idx1];
			sum += arr[idx2];
			//cout<<arr[idx1]<<" "<<arr[idx2]<<" \n";
			idx2--;
			idx1++;
			while(cont < v2[i]){
				idx1++;
				cont++;
			}
		}
		

		//cout<<endl;
		//for(int i = 1; i <= n; ++i)
		//	cout<<arr[i]<<" ";
		//cout<<endl;
		cout<<sum<<"\n";
	}
	return 0;
		
}