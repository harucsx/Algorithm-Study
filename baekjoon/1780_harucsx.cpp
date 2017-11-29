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

int n;
int map[2188][2188];
int result_0, result_m1, result_p1;

void check_paper(int start_x, int start_y, int width) {
    int value = map[start_x][start_y];
    bool check = true;
    for (int i = start_y; i < start_y + width; ++i) {
        for (int j = start_x; j < start_x + width; ++j) {
            if (map[j][i] != value) {
                check = false;
                break;
            }
        }

        if (!check) break;
    }

    if (check) {
        if (value < 0) {
            result_m1++;
            return;
        }
        if (value == 0) {
            result_0++;
            return;
        }
        if (value > 0) {
            result_p1++;
            return;
        }
    }

    int next_width = width / 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            check_paper(start_x + j * next_width, start_y + i * next_width, next_width);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[j][i];
        }
    }

    check_paper(0, 0, n);

    cout << result_m1 << '\n' << result_0 << '\n' << result_p1;
    return 0;
}
