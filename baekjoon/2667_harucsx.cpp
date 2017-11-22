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

int N;
char map[26][26];

int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};

int fill_area(int x, int y) {
    if (!(0 <= x && x < N)) return 0;
    if (!(0 <= y && y < N)) return 0;
    if (map[x][y] != 1) return 0;

    int result = 0;
    map[x][y] = 2;

    for (int i = 0; i < 4; ++i) {
        result += fill_area(x + x_dir[i], y + y_dir[i]);
    }

    return result + 1;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> address;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[j][i];
            map[j][i] -= '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[j][i] == 1) {
                address.push_back(fill_area(j, i));
            }
        }
    }

    sort(address.begin(), address.end());
    cout << address.size() << endl;

    for (int i = 0; i < address.size(); ++i) {
        cout << address[i] << endl;
    }

    return 0;
}
