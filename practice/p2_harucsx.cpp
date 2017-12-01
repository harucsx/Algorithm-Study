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

int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};

void check(int map[51][51], int M, int N, int x, int y) {
    if (!(0 <= x && x < M)) return ;
    if (!(0 <= y && y < N)) return ;
    if (map[x][y] != 1) return ;

    map[x][y] = 2;

    for (int i = 0; i < 4; ++i) {
        check(map, M, N, x + x_dir[i], y + y_dir[i]);
    }

}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; ++tc) {
        queue<pair<int, int> > q;
        int map[51][51];
        int M, N, K;
        int result = 0;
        cin >> M >> N >> K;

        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                map[m][n] = 0;
            }
        }

        for (int k = 0; k < K; ++k) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if (map[m][n] == 1) {
                    check(map, M, N, m, n);
                    result++;
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}
