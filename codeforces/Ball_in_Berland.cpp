#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
const int max_tam = 1e5 + 3;


void solve(){
	int a, b, k;
	map<int,int> map_a, map_b;
	map<pair<int,int>, int> map_pairs;
	cin>>a>>b>>k;
	pair<int,int> pareja[k + 2];


	f(i,k){
		cin>>pareja[i].first;
		map_a[pareja[i].first]++;
	}
	f(i,k){
		cin>>pareja[i].second;
		map_b[pareja[i].second]++;
		map_pairs[pareja[i]]++; //le sumo uno a la pareja 
	}
	//cout<<"las parejas son\n\n";
	/*for(int i = 1; i <= k; ++i){
		cout<<pareja[i].first<<" "<<pareja[i].second<<endl;
	}*/
	//cout<<" \n\n";
	long long int ans = 0;
	f(i,k){
		long long int sumar = 0;
		sumar = sumar + k - 1; //asumo que puedo hacer pareja con todos
		int char_1 = pareja[i].first, char_2 = pareja[i].second;
		sumar = sumar - map_a[char_1] + 1;
		sumar = sumar - map_b[char_2] + 1;
		ans = ans + sumar + map_pairs[pareja[i]] - 1;
		
		//cout<<"para la pareja "<<i<<" sumamos ";
	}
	cout<<ans / 2<<"\n";
	
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();		
	}
	return 0;
}