#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int t, n;
long long int ans;

int gcd(int a, int b) {
    int c;
    while (true) {
        c = a % b;
        if (c == 0) {
            return b;
        }
        a = b;
        b = c;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<int> d;
        d.resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> d[j];
        }
        for (int k = 0; k < n - 1; ++k) {
            for (int j = 1; j < n - k; ++j) {
                ans += gcd(d[k], d[k + j]);
            }
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}