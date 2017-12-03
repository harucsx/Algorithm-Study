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
#include <sstream>

using namespace std;

// vertex, edge
int N, M;

// node info
int start, last;
int max_weight;

// adj list of graph (node, weight)
vector<vector<pair<int, int> > > v;

// visited info
bool visit[100001];

// answer
int result;

bool movable(int from, int to, int weight) {
    if (from == to) return true;

    bool can_move = false;
    visit[from] = true;

    for (int i = 0; i < v[from].size(); ++i) {
        int p = v[from][i].first;
        int w = v[from][i].second;

        if (!visit[p] && weight <= w)
            can_move |= movable(p, to, weight);
    }

    return can_move;
}

void solve(int left, int right) {
    if (left > right) return;

    fill_n(visit, N + 1, false);

    int mid = (left + right) / 2;
    bool can_move = movable(start, last, mid);

    if (can_move) {
        result = max(result, mid);
        solve(mid + 1, right);
    } else {
        solve(left, mid - 1);
    }
}


int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M;

    v.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        max_weight = max(max_weight, w);
        v[x].emplace_back(make_pair(y, w));
        v[y].emplace_back(make_pair(x, w));
    }

    cin >> start >> last;
    solve(1, max_weight);
    cout << result;

    return 0;
}
