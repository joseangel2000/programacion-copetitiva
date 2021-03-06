#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 

void imprimir(vector<char> &s){
	f(i,s.size()){
		cout<<s[i - 1];
	}
	cout<<"\n";
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, k;
	cin>>a>>b>>k;
	
	vector<char> s1, s2;

	////casos especiales 
	if(a == 0){
		if(k > 0){
			cout<<"NO\n";
			return 0;
		}
		if(k == 0){
			cout<<"YES\n";
			f(i,b)
				cout<<"1";
			cout<<"\n";
			f(i, b)
				cout<<"1";
			cout<<"\n";
			return 0;
		}
	}
	if(b == 1){
		if(k > 0){
			cout<<"NO\n";
			return 0;
		}
		if(k == 0){
			cout<<"YES\n";
			cout<<'1';
			f(i,a)
				cout<<"0";
			cout<<"\n";
			cout<<'1';
			f(i, a)
				cout<<"0";
			cout<<"\n";
			return 0;
		}
	}

	if(k == 0){
		cout<<"YES\n";
		f(i,b)
			cout<<'1';
		f(i,a)
			cout<<'0';
		cout<<"\n";
		f(i,b)
			cout<<'1';
		f(i,a)
			cout<<'0';
		return 0;
	}


	if(a + b - 2 < k){
		cout<<"NO";
		return 0;
	}
	




	//caso en el que todos los unos los cargo a la izquierda 
	if(k <= a){
		for(int i = 1; i < b; ++i){
			s1.pb('1');
			s2.pb('1');
		}
		s1.pb('1');
		s2.pb('0');
		for(int i = b + 1; i <= a + b; ++i){
			s1.pb('0');
			if((i - b) == k){
				s2.pb('1');
				continue;
			}
			s2.pb('0');
		}
		cout<<"YES\n";
		imprimir(s1);
		imprimir(s2);
	}
	//caso en el que es mayor a la cantidad de 0
	if(k > a){
		s1.resize(a + b);
		s2.resize(a + b);
		int tam = a + b, cont = 0;;
		for(int i = tam - 1; i >= tam - a; --i){
			cont++;
			s1[i] = '0';
			if(i == tam - 1){
				s2[i] = '1';
				continue;
			}
			s2[i] = '0';
		}
		for(int i = b - 1; i >= 0; --i){
			s1[i] = '1';
			if(cont == k){
				s2[i] = '0';
				cont++;
				continue;
			}
			s2[i] = '1';
			cont++;
		}
		cout<<"YES\n";
		imprimir(s1);
		imprimir(s2);

	}

	return 0;
}