//
// Created by John on 2017-03-15.
//
#include <cstdio>

int map[100][100];

void dfs();
int main() {
    int n;
    scanf("%d", &n);

    int set[100] = {0, };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1)
                set[j] = 1;
        }
    }
    for (int k = 0; k < n; ++k) {
        if(set[k] == 0)
            dfs(k);
    }


}
