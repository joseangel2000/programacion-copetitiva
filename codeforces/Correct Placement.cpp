#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 
#define pii pair<int,int>
#define f(i, n) for(int i = 1; i <= n ; ++i)


int he, wi, aux;

struct person 
{
	int h, w, id;
};
bool operator <(const person &a, const person &b){
	return tie(a.h, a.w, a.id) < tie(b.h, b.w, b.id);
}

void solve(int n){

	vector<person> vec;
	f(i, n){
		cin>>he>>wi;
		if(he > wi){
			aux = he;
			he = wi;
			wi = aux;
		}
		person auxi_p;
		auxi_p.h = he;
		auxi_p.w = wi;
		auxi_p.id = i;
		vec.pb(auxi_p);
	}
	sort(vec.begin(), vec.end());

	/*f(i, n)
		cout<<vec[i - 1].h<<" "<<vec[i - 1].w<<"  "<<vec[i - 1].id<<"\n";
*/
	map<int,pii> mapa;
	vector<pii> element_id;
	//el mapa va a tener como llave el elemento, el .first va a ser el primer elemento en vec con ese numero 
	// y el second va a ser el elemento más pequeño hasta ese momento 

	int elemento = vec[0].h;
	int curr_id = 0;
	int min_wi = vec[0].w;
	element_id.pb(mp(elemento, 0));

	vi sol(n + 2);


	/*f(i, n)
		cout<<"vec["<<i - 1<<"].h = "<<vec[i - 1].h<<" "<<vec[i - 1].w<<"  "<<vec[i - 1].id<<"\n";
	cout<<"\n\n\n";
*/
	for(int i = 0; i < n;++i){
		//cout<<"estoy en i = "<<i<<" ";
		if(vec[i].h == vec[0].h){
		//	cout<<"vec["<<i<<"].h = "<<vec[i].h<<"  vec["<<0<<"].h = "<<vec[0].h<<endl<<endl;
			sol[vec[i].id] = -1;
			continue;
		}
		if(vec[i].h != elemento){
		//	cout<<" aqui el elemento es distinto y min_wi = "<<min_wi<<"  curr_id = "<<curr_id<<"\n\n\n";
			int posible_min_wi = vec[i].w;
			int posible_curr_id = i;
			while(true){
				if(vec[i].w > min_wi){
					sol[vec[i].id] = vec[curr_id].id;
				}
				else if(vec[i].w <= min_wi){
		//			cout<<"con i = "<<i<<" entramos y hacemos -1 a sol en el indice"<<vec[i].id<<endl;
					sol[vec[i].id] = -1;
				}
				i++;

				if(i >= n)
					break;
				if(vec[i].h != vec[i - 1].h){
					i--;
					break;
				}
			//	cout<<"  ll   "<<sol[2]<<endl;
			}
			//cout<<"  ll   "<<sol[2]<<endl;
			elemento = vec[i].h;
			if(posible_min_wi < min_wi){
				min_wi = posible_min_wi;
				curr_id = posible_curr_id;
			}
		}
		//cout<<"\n\n";
	}

	for(int i = 1; i <= n; ++i){
		cout<<sol[i]<<" ";
	}
	cout<<"\n";

}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}

	return 0;
}