#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    unsigned N;
    int result;
    vector<int> v;
    int d[300][2];

    cin >> N;
    v.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    d[0][0] = d[0][1] = 0;
    d[1][0] = d[1][1] = v[1];

    for (int i = 2; i <= N; ++i) {
        d[i][0] = max(d[i - 2][0], d[i - 2][1]) + v[i];
        d[i][1] = d[i - 1][0] + v[i];
    }

    cout << max(d[N][0], d[N][1]);
    return 0;
}
