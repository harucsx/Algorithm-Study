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
char map[64][64];

void quad_tree(int start_x, int start_y, int width) {
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
        if (value == 1) {
            cout << 1;
            return;
        } else if (value == 0) {
            cout << 0;
            return;
        }
    }

    int next_width = width / 2;

    cout << '(';
    quad_tree(start_x, start_y, next_width);
    quad_tree(start_x + next_width, start_y, next_width);
    quad_tree(start_x, start_y + next_width, next_width);
    quad_tree(start_x + next_width, start_y + next_width, next_width);
    cout << ')';
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
            map[j][i] -= '0';
        }
    }

    quad_tree(0, 0, n);
    return 0;
}
