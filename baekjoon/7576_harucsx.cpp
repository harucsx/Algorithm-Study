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

int map[1001][1001];
bool visit[1001][1001];

int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};


int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M;
    queue<pair<pair<int, int>, int> > q;
    cin >> M >> N;
    int result = 0;
    bool all_done = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int in;
            cin >> in;
            map[j][i] = in;

            if (in == 1) {
                q.push(make_pair(make_pair(j, i), 0));
                visit[j][i] = true;
            } else if (in == 0) {
                all_done = false;
            }
        }
    }

    if (all_done) {
        cout << 0;
        return 0;
    }


    while (!q.empty()) {
        pair<int, int> pos = q.front().first;
        int xpos = pos.first;
        int ypos = pos.second;
        int distance = q.front().second;

        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x = pos.first + x_dir[i];
            int next_y = pos.second + y_dir[i];

            if (next_x < 0 || next_x >= M) continue;
            if (next_y < 0 || next_y >= N) continue;

            if (map[next_x][next_y] >= 0 && !visit[next_x][next_y]) {
                visit[next_x][next_y] = true;
                map[next_x][next_y] = distance + 1;
                q.push(make_pair(make_pair(next_x, next_y), distance + 1));
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            result = max(result, map[j][i]);

            if (map[j][i] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << result;
    return 0;
}
