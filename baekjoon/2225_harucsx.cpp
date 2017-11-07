#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long int v[210][210];

long long int get(int N, int K) {
    if (K == 1) return 1;
    if (K == 2) return N + 1;

    if (N == 0) return 1;
    if (N == 1) return K;
    if (v[N][K] > 0)
        return v[N][K];

    long long int result = 0;

    for (int n = N; n >= 0; --n) {
        result += get(n, K-1);
        result %= 1000000000;
    }

    v[N][K] = result % 1000000000;
    return result;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    unsigned N, K;


    cin >> N >> K;

    cout << get(N, K);


    return 0;
}
