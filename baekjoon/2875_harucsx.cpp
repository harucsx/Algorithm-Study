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
    int N, M, K;
    int result;

    cin >> N >> M >> K;
    result = min(N / 2, M);

    if (result < M)
        K -= M - result;

    if (result * 2 < N)
        K -= N - result * 2;

    if (K < 0) K = 0;

    result -= (K + 2) / 3;
    if (result < 0) result = 0;

    cout << result;
    return 0;
}
