#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    int max_value = -1;
    vector<int> v, prime;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        max_value = max(max_value, v[i]);
    }

    // 소수 0, 소수 아님 1
    prime.resize(max_value + 10);
    prime[1] = 1;

    int last_search = (int) sqrt(max_value);
    for (int i = 2; i <= last_search + 1; ++i) {
        for (int j = 1; i * j <= max_value; ++j) {
            if (j > 1)
                prime[i * j] = 1;
        }
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        if (!prime[v[i]])
            result++;
    }

    cout <<result;
    return 0;
}
