#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

struct segmento{
	int inicio;
	int final;
	bool operator <(const segmento &p)const{
		if(final < p.final)
			return true;
		return false;
	}
};



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;cin>>n;
	segmento arr[n + 5];
	for(int i = 1; i <= n ; ++i){
		cin>>arr[i].inicio>>arr[i].final;
		if(arr[i].inicio  > arr[i].final){
			swap(arr[i].inicio,arr[i].final);
		}
	}

	arr[n + 1].inicio = arr[n + 1].final = 100000; //agrego uno grandote al final 

	sort(arr + 1, arr + n + 1);

	/*for(int i = 1; i <= n ; ++i){
		cout<<arr[i].inicio<<" "<<arr[i].final<<endl;

	}*/


	vi vec;

	int idx = 1; 
	while(idx <= n){
		int aux = arr[idx].final;
		while(arr[idx + 1].inicio <= aux)
			idx++;
		vec.pb(aux);
		idx++;
	}
		//////////////////////////////////////////7
	//cout<<endl<<endl<<endl;

	cout<<vec.size()<<"\n";
	floop(i,(int)vec.size())
		cout<<vec[i]<<" ";



	return 0;
}