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

int n, r, c;
int cnt;
int result = -1;

void z(int x, int y, int n) {
    if (result != -1) return;
    if (x == c && y == r && n == 1) {
        result = cnt;
        return;
    }

    if (n == 1) {
        cnt++;
        return;
    }

    int d = n / 2;
    z(x, y, d);
    z(x + d, y, d);
    z(x, y + d, d);
    z(x + d, y + d, d);

}

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> r >> c;
    z(0, 0, (int) (pow(2, n) + 0.1));
    cout << result;
    return 0;
}
