//
// Created by John on 2017-03-15.
//[Complete!]

#include <cstdio>

int move_x[4] = {-1, 0, 1, 0};
int move_y[4] = {0, 1, 0, -1};


void dfs(int map[50][50], int m, int n, int x, int y) {
    map[x][y] = 0;
    //int isEnd = 0; //true

    for (int i = 0; i < 4; ++i) {
        if (x + move_x[i] >= 0 && x + move_x[i] < m &&
            y + move_y[i] >= 0 && y + move_y[i] < n &&
            map[x + move_x[i]][y + move_y[i]] == 1) {
            //false
            dfs(map, m, n, x + move_x[i], y + move_y[i]);
        }
    }
    //if (isEnd == 0)
    //(*count)++;

}

int main() {
    int T;
    scanf("%d", &T);
    for (int l = 0; l < T; ++l) {
        int map[50][50] = {0,};

        int m, n, k;
        scanf("%d %d %d", &m, &n, &k);
        int a, b;
        int count = 0;

        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &a, &b);
            map[a][b] = 1;
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (map[j][i]) {
                    count++;
                    dfs(map, m, n, j, i);
                }

            }
        }
        printf("%d\n", count);
    }

}
