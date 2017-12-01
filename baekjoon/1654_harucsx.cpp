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

long long K, N;
long long result = -1;
vector<long long> lan;

bool check(long long n) {
    long long cnt = 0;
    for (long long i = 0; i < K; ++i) {
        cnt += lan[i] / n;
    }

    return cnt >= N;
}

void search(long long start, long long end) {
    if (start > end) return;

    long long mid = (start + end) / 2;
    if (check(mid)) {
        result = max(result, mid);
        search(mid + 1, end);
    } else {
        search(start, mid - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long max_len = 0;
    cin >> K >> N;

    for (int i = 0; i < K; ++i) {
        long long len;
        cin >> len;
        max_len = max(max_len, len);
        lan.push_back(len);
    }

    search(1, max_len);
    cout << result;
    return 0;
}
