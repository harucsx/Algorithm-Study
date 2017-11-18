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
    int M, N;
    vector<int> v, prime;
    cin >> M >> N;
    v.resize(N);

    // 소수 0, 소수 아님 1
    prime.resize(N + 10);
    prime[1] = 1;

    int last_search = (int) sqrt(N);
    for (int i = 2; i <= last_search + 1; ++i) {
        for (int j = 1; i * j <= N; ++j) {
            if (j > 1)
                prime[i * j] = 1;
        }
    }

    for (int i = M; i <= N; ++i) {
        if(!prime[i])
            cout << i << '\n';
    }
    return 0;
}
