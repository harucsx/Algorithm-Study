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
    int result = -1;
    vector<int> v, r;


    cin >> N;
    v.resize(N + 1);
    r.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    r[0] = 1;
    r[1] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (v[i] > v[j]) {
                r[i] = max(r[i], r[j] + 1);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        result = max(result, r[i]);
    }

    cout << result;
    return 0;
}
