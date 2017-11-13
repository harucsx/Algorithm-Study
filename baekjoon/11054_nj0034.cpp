#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> d, mu, md;
    d.resize(n + 1);
    mu.resize(n + 1);
    md.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int j = 1; j <= n; ++j) {
        mu[j] = 1;
        for (int k = 1; k < j; ++k) {
            if (d[k] < d[j]) {
                mu[j] = max(mu[j], mu[k] + 1);
            }
        }
    }
    for (int j = n; j >= 1; --j) {
        md[j] = 1;
        for (int k = n; k > j; --k) {
            if (d[k] < d[j]) {
                md[j] = max(md[j], md[k] + 1);
            }
        }
    }
    for (int l = 1; l <= n; ++l) {
        m = max(mu[l] + md[l] - 1, m);
    }
    cout << m;
    return 0;
}