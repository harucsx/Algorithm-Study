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

int n, data[8], check[8], m;

int absol(int a, int b) {
    if (a >= b) {
        return a - b;
    } else {
        return b - a;
    }
}

void dfs(int now, int num, int s) {
    if (num == n - 1) {
        m = max(s, m);
        return;
    }
    check[now] = 1;
    for (int i = -now; i < n - now; ++i) {
        if (i != 0 && !check[now + i]) {
            dfs(now + i, num + 1, s + absol(data[now], data[now + i]));
            check[now + i] = 0;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int j = 0; j < n; ++j) {
        scanf(" %d", &data[j]);
    }
    for (int i = 0; i < n; ++i) {
        dfs(i, 0, 0);
        check[i] = 0;
    }

    cout << m;
    return 0;
}