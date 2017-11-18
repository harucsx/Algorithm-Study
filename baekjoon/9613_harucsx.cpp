#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


long long int gcd(int a, int b) {
    if (!a || !b) return 0;
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; ++tc) {
        int N;
        long long int result = 0;
        vector<int> v;
        cin >> N;

        v.resize(N);

        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                result += gcd(v[i], v[j]);
            }
        }

        cout << result << '\n';
    }

    return 0;
}
