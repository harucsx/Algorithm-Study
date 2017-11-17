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
    vector<int> v, sum;


    cin >> N;
    v.resize(N + 1);
    sum.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        sum[i] = v[i];
    }


    for (int i = 2; i <= N; ++i) {
        sum[i] = max(sum[i], sum[i - 1] + v[i]);
    }

    for (int i = 1; i <= N; ++i) {
        result = max(result, sum[i]);
    }

    cout << result;
    return 0;
}
