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



int z(int x, int y, int n) {
    if (n == 2)
        return x + 2 * y;

    int result = 0;
    int next_n = n / 2;
    if (x < next_n && y < next_n) {
        result += z(x, y, next_n);
    } else if (x >= next_n && y < next_n) {
        result += z(next_n - 1, next_n - 1, next_n) + 1;
        result += z(x - next_n, y, next_n);
    } else if (x < next_n && y >= next_n) {
        result += 2 * (z(next_n - 1, next_n - 1, next_n) + 1);
        result += z(x, y - next_n, next_n);
    } else if (x >= next_n && y >= next_n) {
        result += 3 * (z(next_n - 1, next_n - 1, next_n) + 1);
        result += z(x - next_n, y - next_n, next_n);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, r, c;
    int result;
    cin >> n >> r >> c;
    result = z(c, r, 1 << n);
    cout << result;
    return 0;
}
