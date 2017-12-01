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

int n, m, ans;
char a[102][102];
int dis[102][102];

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    dis[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x == m && y == n){
            ans = dis[m][n];
            break;
        }

        if (a[x + 1][y] == '1' && !dis[x + 1][y]) {
            q.push(make_pair(x + 1, y));
            dis[x + 1][y] = dis[x][y] + 1;
        }
        if (a[x - 1][y] == '1' && !dis[x - 1][y]) {
            q.push(make_pair(x - 1, y));
            dis[x - 1][y] = dis[x][y] + 1;
        }
        if (a[x][y + 1] == '1' && !dis[x][y + 1]) {
            q.push(make_pair(x, y + 1));
            dis[x][y + 1] = dis[x][y] + 1;
        }
        if (a[x][y - 1] == '1' && !dis[x][y - 1]) {
            q.push(make_pair(x, y - 1));
            dis[x][y - 1] = dis[x][y] + 1;
        }
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %c", &a[j][i]);
        }
    }
    bfs(1, 1);
    printf("%d", ans);
    return 0;
}