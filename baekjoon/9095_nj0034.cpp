#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, N;

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> d;
    cin >> n;
    d.resize(11);
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int j = 0; j < n; ++j) {
        cin >> N;
        for (int i = 4; i < N + 1; ++i) {
            if (d[i]) {
                continue;
            }
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        cout << d[N] << endl;
    }
    return 0;
}
