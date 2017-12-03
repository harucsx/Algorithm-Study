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

long long N, C;
long long result = -1;
vector<long long> house;

bool check(long long n) {
    long long left = C - 1;
    long long last = house[0];
    for (long long i = 1; i < N; ++i) {
        if (house[i] >= last + n) {
            last = house[i];
            left--;

            if (left <= 0) break;
        }
    }
    return left <= 0;
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
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long max_len = 0;
    cin >> N >> C;

    for (int i = 0; i < N; ++i) {
        long long len;
        cin >> len;
        max_len = max(max_len, len);
        house.push_back(len);
    }

    sort(house.begin(), house.end());

    search(1, max_len);
    cout << result;
    return 0;
}
