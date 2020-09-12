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
	vi primos;
	bool criba[100001];
	floop(i,10001) criba[i] = 1;
	criba[0] = 0; criba[1] = 0;
	for(int i = 2 ; i <5000 ; ++i){
		if(criba[i] == 1){
			for(int  j = i * 2 ; j <= 10000 ; j += i ){
				criba[j] = 0;
			}
		}
	}
	for(int i = 0; i < 10000 ; ++i)
		if(criba[i] == 1)
			primos.pb(i);
	



	int n;
	cin>>n;
	int arr[n + 10];
	int d1[n + 10], d2[n + 10];
	floop(i,n) cin>>arr[i];
	int aux;
	for(int i = 0 ; i < n ; ++i){
		if(arr[i] % 2 == 0){
			aux = arr[i];
			while(aux % 2 == 0)
				aux /= 2;
			if(aux == 1){
				d1[i] = -1;
				d2[i] = -1;
				continue;
			}
			d1[i] = 2; d2[i] = aux;
			continue;
		}
		if(arr[i] % 2 == 1){
			aux = arr[i];
			int flag = 0 ; 
			for(int j = 0 ; j < primos.size() ; ++j){
				if(aux % primos[j] == 0){
					flag++;
					if(flag == 1){
						while(aux % primos[j] == 0)
							aux /= primos[j];
						if(aux == 1){
							d1[i] = -1; d2[i] = -1;
							break;
						}
						d1[i] = primos[j];
						continue;
					}
					if(flag == 2){
						d2[i] = primos[j];
						break;
					}
				}
			}
		}
	
	}
	for(int i = 0 ; i < n ; ++i)
			cout<<d1[i]<<" ";
		cout<<"\n";
		for(int i = 0 ; i < n ; ++i)
			cout<<d2[i]<<" ";


	return 0;
}