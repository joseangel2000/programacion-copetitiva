#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
#define ll long long int
#define mp make_pair

int n,aux;

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		int a[ 2 * n + 5];
		f(i,2*n)
			cin>>a[i];
		sort(a + 1, a + 2*n + 1);
		

		int num_1, num_2, pos_1, pos_2, x;
		vector<pair<int,int> > sol;
		map<int, stack<int> > position;
		bool solucionado = false;
		map<int,bool> taken;

		for(int i = 2* n - 1; i >= 1; --i){
			if(solucionado)
				break;
			sol.clear();
			pos_1 = 2*n;
			pos_2 = i;
			num_1 = a[pos_1]; 
			num_2 = a[pos_2];

			f(j,2*n)
				while(!position[j].empty())
					position[j].pop();
			f(j,2*n){
				taken[j] = false;
				if(j != pos_1 && j != pos_2)
					position[a[j]].push(j);
			}
			
			//cout<<"antes de empezar pos"
			/*f(k, 2*n){
				cout<<"las pociciones para "<<k<<" es ";
				if(position[k].empty ()){
					cout<<"no etsiste\n";
					continue;
				}
				cout<<position[k].top()<<"\n";
			}*/


			taken[pos_1] = true;
			taken[pos_2] = true;
			int tomados = 2 ;
			int xaux = num_2 + num_1;
			sol.pb(mp(xaux,x));
			sol.pb(mp(num_1, num_2));
			while(true){
				//cout<<"num_1 = "<<num_1<<"   num_2 = "<<num_2<<"   pos_1 = "<<pos_1<<" pos_2 = "<<pos_2<<endl; 
				if(tomados == 2 * n){
					solucionado = true;
					break;
				}
				xaux = a[pos_1];
				while(taken[pos_1])
					pos_1--;
				num_1 = a[pos_1];
				position[num_1].pop();
				taken[pos_1] = true;
				num_2 = xaux - num_1;

				if(position[num_2].empty())
					break;
				pos_2 = position[num_2].top();
				if(num_1 == 2)
				position[num_2].pop();
				taken[pos_2] = true;
				tomados += 2;
				sol.pb(mp(num_1,num_2));
			}


		}
		if(solucionado){
			cout<<"YES\n";
			cout<<sol[0].first<<"\n";
			f(i,sol.size() - 1)
				cout<<sol[i].first<<" "<<sol[i].second<<"\n";
			continue;
		}
		cout<<"NO\n";
		
	}
	return 0;
}