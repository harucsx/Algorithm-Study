#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;

    long long int count[10][101];
    long long int result = 0;

    for (int i = 1; i < 10; ++i) {
        count[i][1] = 1;
    }

    count[0][1] = 0;

    for (int i = 2; i <= N; ++i) {
        count[0][i] = count[1][i - 1] % 1000000000;
        count[9][i] = count[8][i - 1] % 1000000000;
        for (int j = 1; j <= 8; ++j) {
            count[j][i] = (count[j - 1][i - 1] + count[j + 1][i - 1]) % 1000000000;
        }
    }

    for (int i = 0; i < 10; ++i) {
        result += count[i][N] % 1000000000;
    }

    cout << result % 1000000000;
    return 0;
}
