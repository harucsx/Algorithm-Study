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
    v[0] = 0;
    v[1] = 1;
    v[2] = 3;

    for (int i = 3; i <= N; ++i) {
        v[i] = (v[i - 1] + 2 * v[i - 2]) % 10007;
    }

    cout << v[N] % 10007;
    return 0;
}
