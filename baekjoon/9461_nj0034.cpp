#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, N;
long long int d[101];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    d[1] = d[2] = d[3] = 1;
    d[4] = d[5] = 2;
    for (int i = 6; i <= 100; ++i) {
        d[i] = d[i-1] + d[i-5];
    }
    for (int j = 0; j < n; ++j) {
        cin >> N;
        cout << d[N] << endl;
    }
    return 0;
}