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

int m, n, z, ans;
int a[1001][1001], day[1001][1001];
queue<pair<int, int> > q;

void bfs(int x, int y) {
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x + 1 < m && a[x + 1][y] == 0) {
            q.push(make_pair(x + 1, y));
            a[x + 1][y] = 1;
            day[x + 1][y] = day[x][y] + 1;
            z--;
        }
        if (x - 1 >= 0 && a[x - 1][y] == 0) {
            q.push(make_pair(x - 1, y));
            a[x - 1][y] = 1;
            day[x - 1][y] = day[x][y] + 1;
            z--;
        }
        if (y + 1 < n && a[x][y + 1] == 0) {
            q.push(make_pair(x, y + 1));
            a[x][y + 1] = 1;
            day[x][y + 1] = day[x][y] + 1;
            z--;
        }
        if (y - 1 >= 0 && a[x][y - 1] == 0) {
            q.push(make_pair(x, y - 1));
            a[x][y - 1] = 1;
            day[x][y - 1] = day[x][y] + 1;
            z--;
        }
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &a[j][i]);
            if (a[j][i] == 0) {
                z++;
            } else if (a[j][i] == 1) {
                q.push(make_pair(j, i));
            }
        }
    }
    bfs(0, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, day[j][i]);
        }
    }
    if(z == 0){
        cout << ans;
    }else{
        cout << "-1";
    }
    return 0;
}