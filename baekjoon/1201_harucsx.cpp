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
    int N, M, K;
    vector<pair<int, int> > v;
    cin >> N >> M >> K;

    if (N < M + K - 1 || N > M * K) {
        cout << -1;
        return 0;
    }

    int start = K + 1;
    int group = 1;
    int max_cnt = K;
    int cnt;

    v.push_back(make_pair(1, K));

    while (group++ < M) {
        cnt = min(max_cnt, (N - start + 1) - (M - group));
        cnt = (cnt < 1) ? 1 : cnt;
        v.push_back(make_pair(start, start + cnt - 1));
        start += cnt;
    }

    for (int i = 0; i < v.size(); ++i) {
        for (int k = v[i].second; k >= v[i].first; --k) {
            cout << k << ' ';
        }
    }

    return 0;
}
