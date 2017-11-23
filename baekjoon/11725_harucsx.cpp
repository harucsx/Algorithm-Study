#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    bool visited[100001];
    int parent[100001];
    vector<int> tree[100001];
    queue<int> q;
    cin >> N;

    fill_n(visited, 100001, false);

    for (int i = 0; i < N - 1; ++i) {
        int p, q;
        cin >> p >> q;
        tree[p].push_back(q);
        tree[q].push_back(p);
    }

    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = true;

        for (int i = 0; i < tree[now].size(); ++i) {
            if (!visited[tree[now][i]]){
                parent[tree[now][i]] = now;
                q.push(tree[now][i]);
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }

    return 0;
}
