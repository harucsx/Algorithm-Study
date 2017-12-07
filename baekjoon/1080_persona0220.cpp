#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr1[51][51];
int arr2[51][51];

void change(int x, int y){

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			arr1[x+i][y+j] = 1 - arr1[x+i][y+j];
		}
	}

}

int main(){

	int N, M;
	scanf("%d %d", &N, &M);


	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1d", &arr1[i][j]);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1d", &arr2[i][j]);
		}
	}

	int cnt = 0;
	for(int i=0; i+2<N; i++){
		for(int j=0; j+2<M; j++){
			if(arr1[i][j] != arr2[i][j]){
				//3*3 Change!
				//				change(i, j);
				//								cnt++;
				//											}
				//													}
				//														}
				//															
				//																for(int i=0; i<N; i++){
				//																		for(int j=0; j<M; j++){
				//																					if(arr1[i][j] != arr2[i][j]){
				//																									printf("-1\n");
				//																													return 0;
				//																																}
				//																																		}
				//																																			}
				//
				//																																				printf("%d\n", cnt);
				//
				//																																					return 0;
				//																																					}
