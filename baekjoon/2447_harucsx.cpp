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
bool map[2200][2200];

void star(int start_x, int start_y, int width) {
    if (width == 3) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                map[start_x + j][start_y + i] = true;
            }
        }

        map[start_x + 1][start_y + 1] = false;
        return;
    }

    int next_width = width / 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
           star(start_x + j*next_width, start_y + i*next_width, next_width);
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

    if (n==1){
        cout << '*';
        return 0;
    }

    star(0, 0, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ((map[j][i]) ? '*' : ' ');
        }
        cout << '\n';
    }
    return 0;
}
