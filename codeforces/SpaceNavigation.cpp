#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

int px, py, x ,y;
		string s;

void move(char c){
	if(c == 'U'){
		y++;
		return ;
	}
	if(c == 'D'){
		y--;
		return ;
	}
	if(c == 'L'){
		x--;
		return ;
	}
	if(c == 'R'){
		x++;
		return ;
	}
}

int main(){

	int t;
	cin>>t;

	while(t--){
		x = 0; y = 0;
		cin>>px>>py;
		bool flag = true;
		cin>>s;

		//cout<<"aqui si llego \n\n";
		if(px >= 0 and py >= 0){
		//	cout<<"entro al primero\n\n";
			int r = 0; int u = 0;
			for(int i = 0 ; i < s.size(); ++i){
				move(s[i]);
				if(s[i] == 'R')
					r++;
				if(s[i] == 'U')
					u++;
				if(u >= py && r >= px){
					cout<<"YES\n";
					flag = false;
					break;
				}
			}

		}
		if(px >= 0 and py <= 0 and flag){
			//cout<<"entro al segundo\n\n";
			int r = 0; int d = 0;
			for(int i = 0 ; i < s.size(); ++i){
				move(s[i]);
				if(s[i] == 'R')
					r++;
				if(s[i] == 'D')
					d++;
				if((-1)*d <= py && r >= px){
					cout<<"YES\n";
					flag = false;
					break;
				}
			}

		}
		if(px <= 0 and py >= 0 and flag){
			//cout<<"entro al tercero\n\n";
			int l = 0; int u = 0;
			for(int i = 0 ; i < s.size(); ++i){
				move(s[i]);
			//	cout<<"si me meti al for l = "<<l<<"  u = "<<u<<endl;
				if(s[i] == 'L')
					l++;
				if(s[i] == 'U')
					u++;

				if(u >= py && (-1)*l <= px){
			//		cout<<u<<" >= "<<y<<"  y  "<<(-1)*l<<" <= "<<x<<endl;
					cout<<"YES\n";
					flag = false;
					break;
				}
			}

		}
		if(px <= 0 and py <= 0 and flag){
			//cout<<"entro al cuarto \n\n";
			int l = 0; int d = 0;
			for(int i = 0 ; i < s.size(); ++i){
				move(s[i]);
			//	cout<<"si me meti al for l = "<<l<<"  d = "<<d<<endl;
				if(s[i] == 'L')
					l++;
				if(s[i] == 'D')
					d++;
				if((-1)*d <= py && (-1)*l <= px){
					cout<<"YES\n";
					flag = false;
					break;
				}
			}

		}
		if(flag)
			cout<<"NO\n";

	}
}