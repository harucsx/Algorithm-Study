#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    unsigned N;
    vector<int> count;

    cin >> N;
    count.resize(N + 1);
    fill(count.begin(), count.end(), N + 20);

    for (int i = 1; i * i <= N; ++i) {
        int i2 = i * i;
            count[i2] = 1;
        for (int j = i2; j <= N; ++j) {
            count[j] = min(count[j - i2] + 1, count[j]);
        }
    }

    cout << count[N];
    return 0;
}
