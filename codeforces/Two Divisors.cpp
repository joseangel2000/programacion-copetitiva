#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define maxi 10000001

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int criba[maxi];
	floop(i,maxi) criba[i] = i ; 
	criba[0] = 1;
	for(int i = 4 ; i < maxi ;  i += 2)
		criba[i] = 2;
	int lim = sqrt(maxi);
	for(int i = 3; i <= lim ; i += 2){
		if(criba[i] == i){
			for(int j = i * i; j < maxi; j += i )
				if(criba[j] > i)
					criba[j] = i;
		}
	}
	



	int n;
	cin>>n;
	int arr[n + 10];
	int d1[n + 10], d2[n + 10];
	floop(i,n) cin>>arr[i];

	for(int i = 0 ; i < n ; ++i){
		//cout<<arr[i]<<" "<<criba[arr[i]]<<endl;
		if(criba[arr[i]] == arr[i]){
			d1[i] = -1;
			d2[i] = -1;
			//cout<<arr[i]<<" "<<criba[arr[i]]<<" "<<d1[i]<<" "<<d2[i]<<endl;
	
			continue;
		}

		int k = arr[i];
		int aux = criba[k];

		while(k % aux == 0){
			k = k / aux;
		}
		if(k == 1){
			d1[i] = -1;
			d2[i] = -1;
			continue;
		}
		d1[i] = aux;
		d2[i] = k;
		
		//cout<<arr[i]<<" "<<criba[arr[i]]<<" "<<d1[i]<<" "<<d2[i]<<endl;
	}
	for(int i = 0 ; i < n ; ++i)
		cout<<d1[i]<<" ";
		cout<<"\n";
	for(int i = 0 ; i < n ; ++i)
		cout<<d2[i]<<" ";


	return 0;
}