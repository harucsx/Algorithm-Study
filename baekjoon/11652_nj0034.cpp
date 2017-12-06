#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int n, cnt = 1, m = 1;
long long int ans;

bool cmp(long long int u, long long int v) {
    return u > v;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<long long int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num.begin(), num.end(), cmp);
    for (int j = 0; j < n; ++j) {
        if (j < n - 1 && num[j] == num[j + 1]) {
            cnt++;
        } else {
            if (cnt >= m) {
                m = cnt;
                ans = num[j];
            }
            cnt = 1;
        }
    }
    cout << ans;

    return 0;
}