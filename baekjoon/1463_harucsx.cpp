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
    int N;
    vector<int> v;

    cin >> N;

    v.resize(N + 1);
    v[0] = INT_MAX / 2;
    v[1] = 0;
    v[2] = 1;
    for (int i = 3; i <= N; ++i) {
        v[i] = v[i - 1] + 1;

        if (i % 3 == 0)
            v[i] = min(v[i], v[i / 3] + 1);

        if (i % 2 == 0)
            v[i] = min(v[i], v[i / 2] + 1);
    }

    cout << v[N];
    return 0;
}
