#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair

int N,M, source, destination, start, endi, duration;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin>>N>>M;
	while(N && M){
		int ans[M + 5]; floop(i,M)ans[i + 1] = 0;
		pair<int,int> calls[N + 5];
		pair<int, int> interval[M + 5];
		for(int i = 1; i <= N; ++i){
			cin>>source>>destination>>start>>duration;
			endi = start + duration;
			calls[i].first = start;
			calls[i].second = endi;
		}

		for(int i = 0 ;  i < M ; ++i){
			cin>>start>>duration;
			endi = start + duration;
			interval[i + 1].first = start;
			interval[i + 1].second = endi;
		}

		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= M; ++j){
				if(calls[i].first >= interval[j].second || calls[i].second <= interval[j].first)
					continue;
				ans[j]++;
			}
		}

		floop(i, M){
			cout<<ans[i + 1]<<"\n";
		}




		cin>>N>>M;
	}

	return 0;
}