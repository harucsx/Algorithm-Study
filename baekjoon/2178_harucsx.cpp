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

char map[101][101];
bool visit[101][101];

int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};


int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M;
    queue<pair<pair<int, int>, int> > q;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[j][i];
            map[j][i] -= '0';
        }
    }

    q.push(make_pair(make_pair(0, 0), 1));
    visit[0][0] = true;

    while (!q.empty()) {
        pair<int, int> pos = q.front().first;
        int distance = q.front().second;

        if (pos.first == M - 1 && pos.second == N - 1) {
            cout << distance;
            break;
        }

        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x = pos.first + x_dir[i];
            int next_y = pos.second + y_dir[i];

            if (next_x < 0 || next_x >= M) continue;
            if (next_y < 0 || next_y >= N) continue;

            if (map[next_x][next_y] && !visit[next_x][next_y]){
                visit[next_x][next_y] = true;
                q.push(make_pair(make_pair(next_x, next_y), distance + 1));
            }
        }
    }
    return 0;
}
