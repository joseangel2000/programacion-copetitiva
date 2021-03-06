#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 

struct torre{
	int x, y;
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, flag;

	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<torre> rook(m + 1);
		bool visited[m + 3];
		map<int,int> rin_col, rin_row;
		//cout<<"\n\n\n\n";
		f(i, m){
			cin>>rook[i].x>>rook[i].y;
		//	cout<<rook[i].x<<"    "<<rook[i].y<<"\n";
			rin_row[rook[i].y] = i; //ingreso ese rook como el que cubre lo row 
			rin_col[rook[i].x] = i;//ingreso ese como el que cubre la columna
			visited[i] = false;
		}

		int sol = 0;

		f(i, m){ 
			if(rook[i].x == rook[i].y) //si y aestas en la diagoal no te muevo
				continue;

			if(visited[i] == true){ //si y alo visite no lo muevo
				continue;
			}
			if(rin_col[rook[i].y] == 0 && rin_row[rook[i].x] == 0){ //si se puede mover a su col o fila por que nadie se lo impide lo marco como visitado
				visited[i] = true;
				sol++;
				continue;
			}


			stack<int> s;
			s.push(i);
			visited[i] = true;

			bool suma = true;
			while(!s.empty()){  // hago una dfs para visitar los nodos que tienen a alguien que los interrumpe
				int v, u = s.top();
				s.pop();
				visited[u] = true;
				sol++;
				flag = 0;
				if(rin_col[rook[u].y] != 0){
					flag++;
					v = rin_col[rook[u].y];
					if(visited[v] == false){
						visited[v] = true;
						s.push(v);
					}
				}
				if(rin_row[rook[u].x] != 0){
					flag++;
					v = rin_row[rook[u].x];
					if(visited[v] == false){
						visited[v] = true;
						s.push(v);
					}
				}
				if(flag == 1) // si alguno tuvo grado 1 entonces no es un ciclo 
					suma = false;
			}
			if(suma) //si sí era un ciclo entonces una pieza debera moverse mas de una vez
				sol++;
		}

		cout<<sol<<"\n";
	}
	

	return 0;
}