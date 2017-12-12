#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[64][64];

void solve(int x, int y, int len){
	
	bool homo = true;
	for(int i=x; i<x+len; i++){
		for(int j = y; j<y+len; j++){
			if(arr[i][j] != arr[x][y]){
				homo = false;
				break;
			}
		}
		if(!homo) break;
	}

	if(homo){
		printf("%d", arr[x][y]);
	}

	else{
		printf("(");
		solve(x, y, len/2);
		solve(x, y+len/2, len/2);
		solve(x+len/2, y, len/2);
		solve(x+len/2, y+len/2, len/2);
		printf(")");
	}

}

int main(){
	
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%1d", &arr[i][j]);
		}
	}

	solve(0, 0, N);

	return 0;
}

