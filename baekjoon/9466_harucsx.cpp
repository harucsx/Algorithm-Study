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
    int TC, V;
    int map[100001];
    int visit[100001];
    int order[100001];

    cin >> TC;

    for (int tc = 0; tc < TC; ++tc) {
        int result = 0;
        cin >> V;

        fill_n(map, V + 1, 0);
        fill_n(visit, V + 1, 0);
        fill_n(order, V + 1, 0);

        for (int i = 1; i <= V; ++i) {
            int x;
            cin >> x;
            map[i] = x;
        }

        for (int p = 1; p <= V; ++p) {
            if (visit[p])
                continue;

            int node = p;
            int num_node = 0;

            while (true) {
                if (visit[node] == p) {
                    result += ++num_node - order[node];
                    break;
                } else if (visit[node]) {
                    break;
                }

                order[node] = ++num_node;
                visit[node] = p;
                node = map[node];
            }
        }

        cout << V - result << '\n';
    }
    return 0;
}
