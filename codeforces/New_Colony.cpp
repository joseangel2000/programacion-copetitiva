#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

int n, k;
int h[1005];

bool optimo(){
	for(int i = 1; i < n; ++i)
		if(h[i] < h[i + 1])
			return false;
	
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int pos;
		cin>>n>>k;
		for(int i = 1; i <= n; ++i)
			cin>>h[i];
		h[n + 1] = 0;
		bool flag = false;


		for(int ball = 1; ball <= k; ++ball){
			pos = 1;
			//cout<<"\n\n\n";
			while(true){
				//cout<<"entro al while con ball = "<<ball<<" y la pos = "<<pos<<endl;
				if(pos == n + 1){
					pos = -1;
					break;
				}
				if(h[pos + 1] <= h[pos]){
					pos++;
					continue;
				}
				if(h[pos + 1] > h[pos]){
					h[pos]++;
					break;
				}
			}
			if(pos == -1){
				flag = true;
				cout<<-1<<"\n";
				break;
			}
		}
		if(flag == false){
			cout<<pos<<"\n";
		}

	}
	return 0;
}