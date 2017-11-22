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

vector<int> map[20001];
int visit[20001];

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC, V, E;

    // vertex, r-b flag
    queue<pair<int, int> > q;

    cin >> TC;

    for (int tc = 0; tc < TC; ++tc) {
        bool result = true;
        cin >> V >> E;

        for (int i = 0; i < V + 1; ++i) {
            map[i].clear();
        }

        fill_n(visit, V + 1, 0);

        for (int i = 0; i < E; ++i) {
            int x, y;
            cin >> x >> y;

            if (x == y) continue;

            map[x].push_back(y);
            map[y].push_back(x);
        }

        for (int p = 1; p <= V; ++p) {
            if(!visit[p])
                q.push(make_pair(p, 1));

            while (!q.empty()) {
                int now = q.front().first;
                int rb_flag = q.front().second;
                if (!visit[now]) {
                    visit[now] = rb_flag;
                }

                q.pop();

                for (int i = 0; i < map[now].size(); ++i) {
                    if (visit[map[now][i]] == rb_flag) {
                        result = false;
                        break;
                    }

                    if (!visit[map[now][i]]) {
                        q.push(make_pair(map[now][i], ((rb_flag == 1) ? 2 : 1)));
                    }
                }

                if (!result)
                    break;
            }
        }

        cout << ((result) ? "YES" : "NO") << '\n';
    }


    return 0;
}
