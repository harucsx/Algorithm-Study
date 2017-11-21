#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>

using namespace std;

void fact(int start, int end, int *n2, int *n5) {
    for (int i = start; i <= end; ++i) {
        int result = i;

        while (result % 2 == 0) {
            result /= 2;
            (*n2)++;
        }

        while (result % 5 == 0) {
            result /= 5;
            (*n5)++;
        }
    }
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M;
    int n2p = 0, n5p = 0;
    int n2n = 0, n5n = 0;

    cin >> N >> M;

    fact(N - M + 1, N, &n2p, &n5p);
    fact(1, N - M, &n2n, &n5n);

    cout << min(n2p - n2n, n5p - n5n);

    return 0;
}
