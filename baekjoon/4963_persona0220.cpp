#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
int W, H;
int map[51][51];

int cx[8]= {-1, -1, -1, 0, 0, 1, 1, 1};
int cy[8]= {-1, 0, 1, -1, 1, -1, 0, 1};

void move(int x, int y, int cnt){

	map[x][y] = cnt;

	int nx, ny;

	for(int i=0; i<8; i++){
		nx = x + cx[i];
		ny = y + cy[i];
	
		if(nx < 0 || ny < 0 || nx >= H || ny >= W || map[nx][ny] != 1){
			//cannot move
			continue;
		}
		else{
			move(nx, ny, cnt);
		}
	}



}

int main(){


	while(1){
		scanf("%d%d", &W, &H);

		if(W==0 && H ==0) break;

		queue<pair<int, int> > queue;

		for(int i=0; i<H; i++){
			for(int j=0; j<W;j++){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1){
					queue.push(make_pair(i,j));
				}
			}
		}

		int cnt = 2;
		while(!queue.empty()){
			int nowx = queue.front().first;
			int nowy = queue.front().second;
			queue.pop();
			
			if(map[nowx][nowy] == 1){
				move(nowx, nowy, cnt);
				cnt++;
			}

		}

		/* for(int i=0; i<H; i++){
		 *     for(int j=0; j<W; j++){
		 *         printf("%d ", map[i][j]);
		 *     }
		 *     printf("\n");
		 * } */
		
		printf("%d\n", cnt-2);
	}
	

	return 0;
}

