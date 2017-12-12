#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, arr[2187][2187], ans[3];

int solve(int x, int y, int len){
	
	int flag = 0;
	int c = arr[x][y];

	if(len == 1){
		ans[c+1]++;
		return c;
	}

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int r = solve(x+len/3*i, y+len/3*j, len/3);

			if(r == 2 || c!=r) flag = 1;
		}
	}

	if(!flag) ans[c+1] -= 8;
	return flag? 2 : c;

}

int main(){
	
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	solve(0,0,N);

	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);

	return 0;
}

