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

int map[101][101];
int addr[101][101];
int dist[101][101];
bool visit[101][101];

int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};


int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, new_address = 0;
    // x_pos, y_pos | distance, address
    queue<pair<pair<int, int>, int> > q;
    cin >> N;
    int result = N * N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int in;
            cin >> in;
            map[j][i] = (in) ? 1 : 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!map[j][i] || visit[j][i]) continue;

            new_address++;
            q.push(make_pair(make_pair(j, i), 0));

            while (!q.empty()) {
                int xpos = q.front().first.first;
                int ypos = q.front().first.second;
                addr[xpos][ypos] = new_address;

                q.pop();
                for (int i2 = 0; i2 < 4; ++i2) {
                    int next_x = xpos + x_dir[i2];
                    int next_y = ypos + y_dir[i2];

                    if (next_x < 0 || next_x >= N) continue;
                    if (next_y < 0 || next_y >= N) continue;

                    if (map[next_x][next_y] && !visit[next_x][next_y]) {
                        q.push(make_pair(make_pair(next_x, next_y), 0));
                        visit[next_x][next_y] = true;
                    }
                }
            }
        }
    }

#ifdef TEST
    cout << "FIRST ADDRESS OF LAND" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << addr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[j][i]) {
                visit[j][i] = true;
                q.push(make_pair(make_pair(j, i), 0));
            }
        }
    }

    for (int i = 0; i < 101; ++i)
        fill_n(visit[i], 101, 0);

    while (!q.empty()) {
        int xpos = q.front().first.first;
        int ypos = q.front().first.second;
        int distance = q.front().second;
        int address = addr[xpos][ypos];

        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x = xpos + x_dir[i];
            int next_y = ypos + y_dir[i];

            if (next_x < 0 || next_x >= N) continue;
            if (next_y < 0 || next_y >= N) continue;

            if (map[next_x][next_y] >= 0 && !visit[next_x][next_y]) {
                visit[next_x][next_y] = true;
                dist[next_x][next_y] = distance + 1;
                q.push(make_pair(make_pair(next_x, next_y), distance + 1));

                if (!addr[next_x][next_y])
                    addr[next_x][next_y] = address;
            }

            if (addr[xpos][ypos] != addr[next_x][next_y]) {
                if (map[xpos][ypos]) dist[xpos][ypos] = 0;
                if (map[next_x][next_y]) dist[next_x][next_y] = 0;

                result = min(result, dist[xpos][ypos] + dist[next_x][next_y]);
            }
        }
    }
#ifdef TEST
    cout << "LAST ADDRESS OF LAND" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << addr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "LAST MAP OF LAND" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << map[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "LAST DISTANCE OF LAND" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << dist[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "ANSWER : ";
#endif

    cout << result;
    return 0;
}
