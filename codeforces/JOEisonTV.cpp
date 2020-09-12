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


	double n;
	cin>>n;
	double ans = 0;
	while(true){
		ans = ans + 1/n;
		n = n - 1.0;
		if(n == 0.0)break;
	}

	printf("%.5f\n",ans);
	return 0;
}