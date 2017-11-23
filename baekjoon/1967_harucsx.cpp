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
    pair<int, int> max_height = make_pair(-1, 0);
    bool visited[100001];
    // node of vertex, cost
    vector<pair<int, int> > tree[100001];
    // queue of vertex, height
    queue<pair<int, int> > q;
    cin >> N;

    fill_n(visited, 100001, false);

    for (int i = 0; i < N - 1; ++i) {
        int n, n1, n2;
        cin >> n >> n1 >> n2;
        tree[n].push_back(make_pair(n1, n2));
        tree[n1].push_back(make_pair(n, n2));
    }

    q.push(make_pair(1, 0));

    while (!q.empty()) {
        int now = q.front().first;
        int height = q.front().second;

        if (max_height.first < height) {
            max_height.first = height;
            max_height.second = now;
        }
        visited[now] = true;

        for (int i = 0; i < tree[now].size(); ++i) {
            if (!visited[tree[now][i].first]) {
                q.push(make_pair(tree[now][i].first, height + tree[now][i].second));
            }
        }

        q.pop();
    }

    fill_n(visited, 100001, false);
    q.push(make_pair(max_height.second, 0));
    max_height.first = -1;

    while (!q.empty()) {
        int now = q.front().first;
        int height = q.front().second;

        max_height.first = max(max_height.first, height);
        visited[now] = true;

        for (int i = 0; i < tree[now].size(); ++i) {
            if (!visited[tree[now][i].first]) {
                q.push(make_pair(tree[now][i].first, height + tree[now][i].second));
            }
        }

        q.pop();
    }

    cout << max_height.first;
    return 0;
}
