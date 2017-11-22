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

int map[1001];
int visit[1001];

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC, V, E;
    stack<int> s;
    cin >> TC;

    for (int tc = 0; tc < TC; ++tc) {
        int result = 0;
        cin >> V;

        fill_n(map, V + 1, 0);
        fill_n(visit, V + 1, 0);

        for (int i = 1; i <= V; ++i) {
            int x;
            cin >> x;

            map[i] = x;
        }

        for (int p = 1; p <= V; ++p) {
            if (visit[p])
                continue;

            int start = p;
            s.push(p);

            while (!s.empty()) {
                int now = s.top();
                if (!visit[now])
                    visit[now] = true;

                if (visit[map[now]]) {
                    if (map[now] == start)
                        result++;

                    break;
                } else {
                    s.push(map[now]);
                }
            }
        }

        cout << result << '\n';
    }


    return 0;
}
