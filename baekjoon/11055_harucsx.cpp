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
    vector<int> v, r, sum;


    cin >> N;
    v.resize(N + 1);
    r.resize(N + 1);
    sum.resize(N + 1);
    fill(r.begin(), r.end(), 1);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        sum[i] = v[i];
    }


    for (int i = 2; i <= N; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (v[i] > v[j]) {
                if (sum[i] < sum[j] + v[i]) {
                    r[i] = r[j] + 1;
                    sum[i] = sum[j] + v[i];
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        result = max(result, sum[i]);
    }

    cout << result;
    return 0;
}
