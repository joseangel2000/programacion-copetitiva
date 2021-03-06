#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long int 
#define pii pair<int,int>

vector<pii> house;
int n, x, y;

int lef, rig, in_col, up, down, in_row, optimum_col, optimum_row;

void count_col(int col);
void count_row(int row);

void bs_col(int a,int b){
	int l = a, r = b;
	while(true){
		int mid = (l + r) / 2;
		count_col(mid);
		int move_right = rig - lef - in_col;
		int move_left = lef - rig - in_col;
		if(move_right <= 0 && move_left <= 0){
			optimum_col = mid;
			break;
		}
		if(move_right < 0){
			l = mid - 1;
			continue;
		}
		if(move_left < 0){
			r = mid + 1;
			continue;
		}

	}
	return ;
}
void bs_row(int a,int b){
	int d = a, u = b;
	while(true){
		int mid = (d + u) / 2;
		count_row(mid);
		int move_up = up - down - in_row;
		int move_down = down - up - in_row;
		if(move_up <= 0 && move_down <= 0){
			optimum_row = mid;
			break;
		}
		if(move_up < 0){
			u = mid - 1;
			continue;
		}
		if(move_down < 0){
			d = mid + 1;
			continue;
		}

	}
	return ;
}


void solve(){
	//cout<<"hola si entre al solve\n\n";
	house.clear();
	int max_left = INT_MAX - 1, max_right = 0, max_up = 0, max_down = INT_MAX - 1;
	//cout<<"hola antes que nada\n\n";
	f(i, n){
		cin>>x>>y;
		house.pb(mp(x,y));
		max_down = min(max_down, y);
		max_up = max(max_up, y);
		max_right = max(max_right, x);
		max_left = min(max_left, x);
	}

	//cout<<"hola, estoy antes de la bs\n\n";
	bs_col(max_left, max_right);
	//cout<<"optimum_co = "<<optimum_col;
	bs_row(max_down, max_up);
	//cout<<"   optimum_row = "<<optimum_row<<"\n\n";
	//cout<<"hola llehue despues de las bs\n\n\n";
	//count_row(optimum_row);
	//cout<<"la columna optima es "<<optimum_col;
	//cout<<"   la fila optima es "<<optimum_row<<" up = "<<up<<"  down = "<<down<<" in_row = "<<in_row<<"\n\n\n\n" ;

	ll posible_columns = 1, posible_rows = 1 ;
	int aux = optimum_col;
	int clst_ri = INT_MAX- 1, clst_le = -1, clst_up = INT_MAX- 1, clst_dow = -1;
	for(int i = 0; i < n ; ++i){
		int curr_row = house[i].second, curr_col = house[i].first;
		if(curr_col > optimum_col && curr_col < clst_ri)
			clst_ri = curr_col;
		if(curr_col < optimum_col && curr_col > clst_le)
			clst_le = curr_col;
		if(curr_row > optimum_row && curr_row < clst_up)
			clst_up = curr_row;
		if(curr_row < optimum_row && curr_row > clst_dow)
			clst_dow = curr_row;
	}

	//cout<<"\noptimum_col = "<<optimum_col<<" optimum_row = "<<optimum_row<<"\n";
	//cout<<"clst_ri = "<<clst_ri<<" clst_le = "<<clst_le<<"\n";
	//cout<<"clst_dow = "<<clst_dow<<"  clst_up = "<<clst_up<<"\n\n";

	if(clst_ri != INT_MAX -1){
		count_col(clst_ri);
		int move_left = lef - rig -in_col;
	//	cout<<"\n\nclst_ri = "<<clst_ri<<" rig = "<<rig<<" lef = "<<lef<<" in_col = "<<in_col<<"\n\n\n";
		if(move_left == 0){
	//		cout<<"\nme muevo izquierda desde clst_ri";
			posible_columns = posible_columns + clst_ri - optimum_col;
		}
	}
	if(clst_le != - 1){
		count_col(clst_le);
		int move_right = rig - lef - in_col;
		if(move_right == 0){
	//		cout<<"\n me muevo a la derecha desde clsleft";
			posible_columns = posible_columns + optimum_col - clst_le;
		}
	}
	if(clst_up != INT_MAX - 1){
		count_row(clst_up);
		int move_down = down - up - in_row;
		if(move_down == 0){
	//		cout<<"\nme muevo abajo desde clst_up";
			posible_rows = posible_rows + clst_up - optimum_row;
		}
	}
	if(clst_dow != -1){
		count_row(clst_dow);
		int move_up = up - down - in_row;
		if(move_up == 0){
	//		cout<<" \n me muevo up desde clst_dow";
			posible_rows = posible_rows + optimum_row - clst_dow;
		}
	}
	//cout<<"\n posible_rows = "<<posible_rows<<"  posible_columns = "<<posible_columns<<"\n\n";
	cout<<posible_rows * posible_columns<<"\n";
}	



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout<<"hola despues del fast input\n\n\n";
	int t;
	cin>>t;
	while(t--){
		//cout<<"hola t = "<<t<<"\n\n";
		cin>>n;
		solve();
	}
	return 0;
}


void count_col(int col){	
	lef = rig = in_col = 0;
	f(i, n){
		if(house[i -1].first < col)
			lef++;
		else if(house[i - 1].first > col)
			rig++;
		else 
			in_col++;
	}
	return ;
}
void count_row(int row){
	up = down = in_row = 0;
	f(i, n){
		if(house[i -1 ].second < row)
			down++;
		else if(house[i - 1].second > row)
			up++;
		else 
			in_row++;
	}
	return ;
}