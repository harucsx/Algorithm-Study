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
    vector<int> v, inc, dec;


    cin >> N;
    v.resize(N + 1);
    inc.resize(N + 1);
    dec.resize(N + 1);
    fill(inc.begin(), inc.end(), 1);
    fill(dec.begin(), dec.end(), 1);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }


    for (int i = 2; i <= N; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (v[i] > v[j]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    for (int i = N - 1; i > 0; --i) {
        for (int j = i + 1; j <= N; ++j) {
            if (v[i] > v[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        result = max(result, inc[i] + dec[i] - 1);
    }

    cout << result;
    return 0;
}
