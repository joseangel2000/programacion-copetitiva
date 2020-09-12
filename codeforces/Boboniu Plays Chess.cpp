#include<bits/stdc++.h>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)
#define frep(i,start,end) for(int i = start; i <= end ; ++i)
#define vi vector<int>
#define ll long long int
#define pb push_back
#define mp make_pair
int arriba = 1, abajo = 2;
bool mat[105][105];
int m, n;
int x,y,Sx, Sy;
int direccion;

void clean(){
	floop(i, n + 3)
		floop(j , n + 3)
			mat[i][j] = false;
}

void recorrido1(){
	//cout<<"recorrido1\n";
	x = Sx; 
	y = Sy;
	direccion = arriba;
	while(true){
		if(x < 1 || y < 1)
			break;
		cout<<x<<" "<<y<<" \n";
		
		if(direccion == arriba){
			if(x > 1){
				x--;
				continue;
			}
			y--;
			direccion = abajo;
			continue;
		}
		if(direccion == abajo){
			if(x < Sx){
				x++;
				continue;
			}
			y--;
			direccion = arriba;
			continue;
		}

	}
}

void recorrido2(){
	//cout<<"recorrido2\n";
	x = Sx + 1;
	y = 1;
	direccion = abajo;
	
	while(true){
		if(y > m )
			break;
		cout<<x<<" "<<y<<"\n";
		
		if(direccion == abajo){
			if(x < n){
				x++;
				continue;
			}
			y++;
			direccion = arriba;
			continue;
		}
		if(direccion == arriba){
			if(x > Sx + 1){
				x--;
				continue;
			}
			y++;
			direccion = abajo;
			continue;
		}
	}
}
void recorrido3(){
	//cout<<"recorrido3\n";
	x = 1;
	y = m;
	direccion = abajo;
	while(true){
		if(y == Sy)
			break;
		cout<<x<<" "<<y<<"\n";
		if(direccion == abajo){
			if(x < Sx){
				x++;
				continue;
			}
			y--;
			direccion = arriba;
			continue;
		}
		if(direccion == arriba){
			if(x > 1){
				x--;
				continue;
			}
			y--;
			direccion = abajo;
			continue;
		}
	}
}




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>Sx>>Sy;
	recorrido1();
	recorrido2();
	recorrido3();
	return 0;
}