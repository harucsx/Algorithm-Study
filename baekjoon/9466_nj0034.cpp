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

int test, v, team;
int a[100001], check[100001];

void dfs(int n, int i) {
    if (check[n] == i) {
        check[n] = -1;
        team++;
        if (check[a[n]] == -1) {
            return;
        }
        dfs(a[n], i);
    }
    if ((check[n] != 0 && check[n] != i) || check[n] == -1) {
        return;
    }
    check[n] = i;
    dfs(a[n], i);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &test);
    for (int t = 0; t < test; ++t) {
        scanf("%d", &v);
        for (int i = 1; i <= v; ++i) {
            scanf("%d", &a[i]);
        }
        for (int j = 1; j <= v; ++j) {
            dfs(j, j);
        }
        cout << v - team << '\n';
        team = 0;
        memset(check, 0, sizeof(check));
    }
    return 0;
}