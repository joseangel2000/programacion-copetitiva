#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back

ll sum1, sum2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		sum1 = pow(2,n);
		for(int i = 1 ; i < (n / 2) ; ++i){
			sum1 += pow(2,i);
		}
		sum2 = pow(2,n+1) -2;
		sum2 -= sum1;
		cout<<sum1-sum2<<endl;
	}

	return 0;
}