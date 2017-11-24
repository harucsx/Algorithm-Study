#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int dist[101][101] = {0};
int labelmap[101][101] = {0};
int label = 1;

int mx[] = {0, 1, 0, -1};
int my[] = {-1, 0, 1, 0};

int N;
int ans = 987654321;
queue<pair<int, int> > Q;



void labeling(int x, int y){
	
	if(x < 0 || y < 0 || x >= N || y >= N || dist[x][y] == 0) return;
	
	dist[x][y] = 0;
	labelmap[x][y] = label;
	Q.push(make_pair(x, y));

	for(int i=0; i<4; i++){
		labeling(x + mx[i], y + my[i]);
	}
}

int main(){
	
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &dist[i][j]);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(dist[i][j]){
				labeling(i, j);
				label++;
			}
		}
	}

	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for(int i=0; i<4; i++){
			int nx = x + mx[i];
			int ny = y + my[i];

			if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if(labelmap[nx][ny] != 0){
				if(labelmap[nx][ny] != labelmap[x][y]){
					//현재랑 다른 섬이면 섬이 맞닿은 상황이니까 답 계산 후 최소값 업데이트
					ans = min(ans, dist[nx][ny] + dist[x][y]);
				}
			}
			else{
				//다음 칸이 바다면 간척사업!!
				labelmap[nx][ny] = labelmap[x][y];
				dist[nx][ny] = dist[x][y] + 1;
				Q.push(make_pair(nx, ny));
			
			}	
		}
	}

	printf("%d\n", ans);
/* 
 *     for(int i=0; i<N; i++){
 *         for(int j=0; j<N; j++){
 *             printf("%d ", labelmap[i][j]);
 *         }
 *         printf("\n");
 *     }
 *  */

	return 0;
}

