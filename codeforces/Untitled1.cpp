#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair


int n;
string s;

struct cadena{
	string st;
	/*bool operator < (const cadena & p)const{

		if((int)st.size()  < (int)p.st.size()){
			string saux = p.st.substr(0,(int)st.size());
			if(st < saux)
				return true;
			if(st > saux)
				return false;
			if(st == saux)
				return false;
		}

		if((int)st.size()  > (int)p.st.size()){
			string saux = st.substr(0,(int)p.st.size());
			if(saux < p.st)
				return true;
			if(saux > p.st)
				return false;
			if(saux == p.st)
				return true;
		}

		if(st < p.st)
			return true;
		if(st > p.st)
			return false;


	}*/
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	cadena aux;
	vector<cadena> vec;

	for(int i = 0; i < n; ++i){
		cin>>s;
		sort(s.begin(),s.end(), greater<int>());
		aux.st = s;
		vec.pb(aux);
	}
	
	//sort(vec.begin(),vec.end(), greater<int>());
	
	for(int i = 0 ; i < (int)vec.size() ; ++i){
		cout<<vec[i].st;
	}
	return 0;
}
