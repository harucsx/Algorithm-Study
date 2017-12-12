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

int n, node1, node2;
vector<int> a[100001], parent(100001);
queue<int> q;

void bfs(int n) {
    q.push(n);
    parent[n] = n;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < a[now].size(); ++i) {
            if (!parent[a[now][i]]) {
                q.push(a[now][i]);
                parent[a[now][i]] = now;
            }
        }
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node1 >> node2;
        a[node1].push_back(node2);
        a[node2].push_back(node1);
    }
    bfs(1);
    for (int j = 2; j <= n; ++j) {
        printf("%d\n", parent[j]);
    }

    return 0;
}