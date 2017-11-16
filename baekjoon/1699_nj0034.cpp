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
    vector<int> min_v;
    min_v.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        min_v[i] = i;
        for (int j = 1; j*j <= i; ++j) {
            min_v[i] = min(min_v[i - j*j] + 1, min_v[i]);
        }
    }
    cout << min_v[n];
    return 0;
}