#include <stdio.h>

#pragma warning(disable:4996)

int map[52][52];
int visit[52][52]; //unvisit : 0, visited : 1

int mx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int my[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void dfs(int x, int y, int w, int h) {
	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		if ((x + mx[i]) >= 0 && (y + my[i]) >= 0 && (x + mx[i]) < h && (y + my[i]) < w) {
			if (map[x + mx[i]][y + my[i]] == 1 && visit[x + mx[i]][y + my[i]] == 0)
				dfs(x + mx[i], y + my[i], w, h);
		}
	}
	return;
}

int findLand(int w, int h) {
	int sol = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				sol++;
				dfs(i, j, w, h);
			}

		}
	}
	return sol;
}

int main() {
	int w, h;
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int sol = findLand(w, h);
		printf("%d\n", sol);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
	}
}