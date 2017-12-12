#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int n, m, k;
	cin >> n >> m >> k;

	if( m + k -1 <= n && n <= m * k){
		for(int i=1; i<=m; i++){
			for(int j= min(i*k, n-m+i); j> min(i*k-k, n-m+i-1); j--){
				printf("%d ", j);
			}
		}
	}
	else{
		printf("-1\n");
	}

	return 0;
}

