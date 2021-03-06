#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define vi vector<int>
#define pb push_back
const int max_tam = 1e5 + 3;


int n;

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		long long int d[2 * n + 3];
		bool continuar = true;
		for(int i = 1; i <= 2*n; ++i)
			cin>>d[i];
	
		sort(d + 1, d + 1 + 2 * n);
		/*f(i,n){
			cout<<"d["<<2 * i - 1<<"] = "<<d[2 * i - 1]<<"d["<<2 * i <<"] = "<<d[2 * i]<<endl;
		}*/
		f(i,n){
			if(!continuar)
				break;
			if(d[2 * i] != d[2 * i -  1])
				continuar = false;
			if(d[2 * i] % 2 == 1)
				continuar = false;
		}
		f(i,n - 1)
			if(d[2 * i] == d[2 * i + 1]){
				continuar = false;
				break;
			}
		if(continuar == false){
			cout<<"NO\n";
			continue;
		}

		int idx = n;
		long long int acumulada = 0ll;
		/*f(i,n){
			cout<<"d["<<2 * i - 1<<"] = "<<d[2 * i - 1]<<"     d["<<2 * i <<"] = "<<d[2 * i]<<endl;
		}
		cout<<"\n\n\n\n";*/
		while(true){
			
			if(d[2 * idx] % (2*idx) != 0){
	//			cout<<" ya no se pudo carnal d["<<2*idx<<"] = "<<d[2*idx]<<endl;
				continuar = false;
			}
			if(!continuar)
				break;	
			if(idx == 1){
				if(d[2] % 2 == 1 || d[2] <= 0)
					continuar = false;
				//cout<<"d[2] = "<<d[2]<<endl;
				break;
			}
			long long int an = d[2 * idx] / 2 / idx;
			//cout<<"an = "<<d[idx * 2]<<" / "<<(idx * 2)<<"  = "<<an<<endl;
			//cout<<"an = "<<an<<" d["<<idx * 2<<"] = "<<d[idx * 2]<<endl;
			acumulada += an;
			d[2 * (idx - 1)] -= 2 * acumulada;
			//cout<<"con idx = "<<idx<<"   d[2*idx] = "<<d[2*idx]<<"  an = "<<an<<endl<<endl;
			idx--;
		}

		if(continuar == false){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}	
	return 0;
}