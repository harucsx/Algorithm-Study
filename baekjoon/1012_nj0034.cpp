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

int test, m, n, k, p, q, a[50][50], check[50][50], ans;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
bool cab;

void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }
    if (a[x][y] == 0 || check[x][y]) {
        return;
    }
    check[x][y] = 1;
    cab = true;
    for (int i = 0; i < 4; ++i) {
        dfs(x + dir_x[i], y + dir_y[i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> test;
    for (int t = 0; t < test; ++t) {
        cin >> m >> n >> k;
        for (int i = 0; i < k; ++i) {
            scanf(" %d %d", &p, &q);
            a[p][q] = 1;
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                dfs(i, j);
                if(cab){
                    ans++;
                    cab = false;
                }
            }
        }
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}