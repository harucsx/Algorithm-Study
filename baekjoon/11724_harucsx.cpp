#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>

using namespace std;

vector<int> map[1001];
bool visit[1001];

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M;
    int result = 0;

    queue<int> q;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    for (int p = 1; p <= N; ++p) {
        if (visit[p])
            continue;

        q.push(p);

        while (!q.empty()) {
            int now = q.front();
            if (!visit[now]) {
                visit[now] = true;
            }

            q.pop();

            for (int i = 0; i < map[now].size(); ++i) {
                if (!visit[map[now][i]]) {
                    q.push(map[now][i]);
                }
            }
        }

        result++;
    }

    cout << result;

    return 0;
}
