#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

int v, e, start;
int n1, n2;
bool check[1001];
vector<int> a[1001];

void dfs(int n) {
    check[n] = true;
    printf("%d ", n);
    for (int i = 0; i < a[n].size(); ++i) {
        if (!check[a[n][i]]) {
            dfs(a[n][i]);
        }

    }
}

void bfs(int n) {
    check[n] = true;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        printf("%d ", q.front());
        for (int i = 0; i < a[q.front()].size(); ++i) {
            if (!check[a[q.front()][i]]) {
                check[a[q.front()][i]] = true;
                q.push(a[q.front()][i]);
            }
        }
        q.pop();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> v >> e >> start;
    for (int i = 0; i < e; ++i) {
        cin >> n1 >> n2;
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }
    for (int j = 0; j < v; ++j) {
        sort(a[j].begin(), a[j].end());
    }
    dfs(start);
    memset(check, false, sizeof(check));
    cout << '\n';
    bfs(start);

    return 0;
}