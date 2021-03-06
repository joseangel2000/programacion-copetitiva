#include<iostream>
using namespace std;
#define floop(i,n) for(int i = 0 ; i < n ; ++i)


int main(){
	

	int n;
	scanf("%d",&n);
	int a[n + 5], hay[n + 5];

	for(int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
		hay[i] = 0;
	}
	int m,caso,p,x,k;
	scanf("%d",&m);
	floop(i,m){
		scanf("%d",&caso);
		if(caso == 1){
			scanf("%d",&p);
			scanf("%d",&x);
			while(true){
				if(p == n+1) break;
				if(hay[p] + x <= a[p]){
					hay[p] = hay[p] + x;
					break;
				}
				x = x - (a[p] - hay[p]);
				hay[p] = a[p];
				p++;
			}
		}
		if(caso == 2){
			scanf("%d",&k);
			printf("%d\n",hay[k]);
			
		}
	}

	return 0;
}