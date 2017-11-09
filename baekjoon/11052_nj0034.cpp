#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> m, p;
    cin >> N;
    m.resize(N + 1);
    p.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
    }
    m[1] = p[1];
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            m[i] = max(m[i], m[i - j] + p[j]);
        }
    }
    cout << m[N] << endl;
    return 0;
}



