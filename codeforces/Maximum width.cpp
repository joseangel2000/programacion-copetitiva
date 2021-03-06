#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 



int m, n;
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	
	while(T--){

		cin>>n>>m;
		cin>>s>>t;
		
		int sol = 0, idx = 0;
		
		int pos_1[m + 2], pos_2[m + 2];
		
		

		while(true){
			if(s[idx] == t[0] || idx >= n)
				break;
			idx++;
		}

		pos_1[1] = idx; pos_2[1] = idx;
		idx = n - 1;
		
		while(true){
			if(s[idx] == t[m - 1])
				break;
			idx--;
		}

		pos_1[m] = pos_2[m] = idx;


		if(m == 2){
			cout<<pos_2[m] - pos_1[1]<<"\n";
			break;
		}


		int pos = 1;
		idx = pos_1[1] + 1;

		//cout<<"pos 1 = "<<pos_1[1]<<" pos ultima = "<<pos_2[m]<<" \n";
		while(true){
			while(true){
				if(s[idx] == t[pos]){
					pos_1[pos + 1] = idx;
					break;
				}
				idx++;
			}
			pos++;
			idx++;
			if(pos == m - 1)
				break;
		}
		
		pos = m - 2;
		idx = pos_2[m] - 1;
		while(true){
			while(true){
				if(s[idx] == t[pos]){
					pos_2[pos + 1] = idx;
					break;
				}
				idx--;
			}
			idx--;
			pos--;
			if(pos == 0)
				break;
		}
		

		for(int i = 1; i < m; ++i){
			sol = max(sol, pos_2[i + 1] - pos_1[i]);
		}
		cout<<sol<<"\n";
	}
	return 0;
}