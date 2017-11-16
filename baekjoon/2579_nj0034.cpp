#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> d, m;
    d.resize(n + 1);
    m.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    m[1] = d[1];
    m[2] = d[1] + d[2];
    for (int j = 3; j <= n; ++j) {
        m[j] = max(d[j] + m[j - 2], d[j] + d[j - 1] + m[j - 3]);
    }
    cout << m[n];
    return 0;
}