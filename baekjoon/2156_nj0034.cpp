#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
long long int m[10001];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> w;
    w.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    m[1] = w[1];
    m[2] = w[1] + w[2];
    for (int j = 3; j <= n; ++j) {
        m[j] = max(m[j - 1], max(m[j - 3] + w[j - 1] + w[j], m[j - 2] + w[j]));
    }
    cout << m[n];
    return 0;
}