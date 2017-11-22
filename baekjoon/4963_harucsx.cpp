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

int W, H;
char map[51][51];

int x_dir[] = {1, -1, 0, 0, 1, -1, 1, -1};
int y_dir[] = {0, 0, 1, -1, 1, -1, -1, 1};

void fill_area(int x, int y) {
    if (!(0 <= x && x < W)) return ;
    if (!(0 <= y && y < H)) return ;
    if (map[x][y] != 1) return ;

    map[x][y] = 2;

    for (int i = 0; i < 8; ++i) {
        fill_area(x + x_dir[i], y + y_dir[i]);
    }

}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(true){
        int result = 0;
        vector<int> address;
        cin >> W >> H;

        if (!W && !H)
            break;

        if (!W || !H){
            cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> map[j][i];
                map[j][i] -= '0';
            }
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (map[j][i] == 1) {
                    fill_area(j, i);
                    result ++;
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}
