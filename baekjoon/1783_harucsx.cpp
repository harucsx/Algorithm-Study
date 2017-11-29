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

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long int N, M;
    long long int result = -1LL;
    cin >> N >> M;

    if (N <= 1LL) {
        result = 1LL;
    } else if (N == 2LL) {
        result = min((M + 1) / 2, 4LL);
    } else {
        if (M <= 4LL) {
            result = M;
        } else if (M < 7LL) {
            result = 4LL;
        } else {
            result = M - 2LL;
        }
    }

    cout << result;
    return 0;
}
