#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, a, b, final_sec, sol = 0, sec;
	cin>>t;
	while(t--){
		cin>>n>>m>>a>>b;
		
		if(a > b){
			a = n - a + 1;
			b = n - b + 1;
		}

		vi fc(m);
		sol = 0;
		
		f(i, m)
			cin>>fc[i - 1];
		sort(fc.begin(), fc.end());
			

			
		final_sec = b - 1;
		//solo puedo lanzar a - b - q fc;
		int fc_idx =  min(b - a - 2, m - 1);
		sec = 1;
		while(true){
			if(fc_idx < 0)
				break;
			if(fc[fc_idx] + sec > final_sec){
				fc_idx--;
				continue;
			}
			if(fc[fc_idx] + sec <= final_sec){
				fc_idx--;
				sec++;
				sol++;
				continue;
			}
		}
		cout<<sol<<"\n";
		
	}	
	

	return 0;
}