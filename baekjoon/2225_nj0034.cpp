#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k;
long long int d[201][201];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        d[i][1] = 1;
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l < j + 1; ++l) {
                d[j][i] += d[j - l][i - 1] % 1000000000;
            }
        }
    }
    cout << d[n][k] % 1000000000;

    return 0;
}