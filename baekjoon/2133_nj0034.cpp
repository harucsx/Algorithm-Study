#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<long long int> d;
    d.resize(n + 1);
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    for (int i = 3; i <= n; ++i) {
        if (i % 2 == 1) {
            d[i] = 0;
        } else {
            d[i] = 4 * d[i - 2] - d[i - 4];
        }
    }
    cout << d[n];
    return 0;
}