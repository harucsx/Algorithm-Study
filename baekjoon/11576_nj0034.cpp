#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int decimal;
int a, b, m;

void dfs(int n, int div) {
    if (n == 0) {
        return;
    }
    dfs(n / div, div);
    cout << n % div << " ";
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> a >> b >> m;
    if (m == 0) {
        cout << 0;
    } else {
        vector<int> av;
        av.resize(m);
        for (int i = m - 1; i >= 0; --i) {
            cin >> av[i];
        }
        int mul = 1;
        for (int j = 0; j < m; ++j) {
            decimal += av[j] * mul;
            mul *= a;
        }
        dfs(decimal, b);
    }
    return 0;
}