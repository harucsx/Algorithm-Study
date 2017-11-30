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

int w, h, a[52][52], check, land;

void dfs(int x, int y) {
    if (a[x][y] == 0 || a[x][y] == 2) {
        return;
    }
    check = 1;
    a[x][y] = 2;
    dfs(x + 1, y + 1);
    dfs(x + 1, y);
    dfs(x + 1, y - 1);
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x - 1, y + 1);
    dfs(x - 1, y);
    dfs(x - 1, y - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    while (true) {
        scanf(" %d %d", &w, &h);
        if (w == 0 && h == 0) {
            break;
        }
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                scanf(" %d", &a[j][i]);
            }
        }
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                dfs(j, i);
                if(check == 1){
                    land++;
                    check = 0;
                }
            }
        }
        printf("%d\n", land);
        land = 0;
    }
    return 0;
}