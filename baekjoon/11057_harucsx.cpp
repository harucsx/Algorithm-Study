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

    long long int count[10][1010];
    long long int result = 0;

    for (int i = 0; i < 10; ++i) {
        count[i][1] = 1;
    }


    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            count[j][i] = 0;

            for (int k = 0; k <= j; ++k) {
                count[j][i] += count[k][i - 1];
                count[j][i] %= 10007;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        result += count[i][N] % 10007;
    }

    cout << result % 10007;
    return 0;
}
