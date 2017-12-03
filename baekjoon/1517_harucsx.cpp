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

int N;
long long result;
int od[500000], cd[500000];

void check(int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    int left_start = start;
    int left_end = mid;
    int right_start = mid + 1;
    int right_end = end;
    int pos = left_start;
    int left_pos = left_start;
    int right_pos = right_start;

    check(left_start, left_end);
    check(right_start, right_end);

    while (left_pos <= left_end && right_pos <= right_end) {
        if (od[left_pos] > od[right_pos]) {
            result += (long long) (left_end - left_pos + 1);
            cd[pos++] = od[right_pos++];
        } else {
            cd[pos++] = od[left_pos++];
        }
    }

    while (left_pos <= left_end)
        cd[pos++] = od[left_pos++];

    while (right_pos <= right_end)
        cd[pos++] = od[right_pos++];

    for (int i = start; i <= end; ++i)
        od[i] = cd[i];
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> od[i];
    }

    check(0, N - 1);
    cout << result;
    return 0;
}
