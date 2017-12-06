#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int n, a[101][101], check[101][101], dis[101][101];
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};
int island = 1, ans = 200, dis_v;
bool next;
queue<pair<int, int> > q;

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return;
	}
	if (check[x][y] || a[x][y] == 0) {
		return;
	}
	check[x][y] = island;
	next = true;
	q.push(make_pair(x, y));
	for (int i = 0; i < 4; ++i) {
		dfs(x + dir_x[i], y + dir_y[i]);
	}
}

void bfs(int x, int y) {
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (x + dir_x[i] >= 0 && x + dir_x[i] < n && y + dir_y[i] >= 0 && y + dir_y[i] < n && check[x + dir_x[i]][y + dir_y[i]] != check[x][y]) {
				if (check[x + dir_x[i]][y + dir_y[i]] == 0) {
					q.push(make_pair(x + dir_x[i], y + dir_y[i]));
					check[x + dir_x[i]][y + dir_y[i]] = check[x][y];
					dis[x + dir_x[i]][y + dir_y[i]] = dis[x][y] + 1;
				} else {
					dis_v = dis[x][y] + dis[x + dir_x[i]][y + dir_y[i]];
					ans = min(ans, dis_v);
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf(" %d", &a[j][i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dfs(j, i);
			if (next) {
				island++;
				next = false;
			}
		}
	}
	bfs(0, 0);
	cout << ans;
	return 0;
}