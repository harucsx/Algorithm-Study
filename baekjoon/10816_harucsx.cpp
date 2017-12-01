#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M;
    vector<int> v, t;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cin >> M;
    t.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < M; ++i) {
        if (binary_search(v.begin(), v.end(), t[i])) {
            auto p = equal_range(v.begin(), v.end(), t[i]);
            cout << distance(p.first, p.second) << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    return 0;
}
