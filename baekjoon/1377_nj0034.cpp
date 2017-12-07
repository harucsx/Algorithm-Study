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

int n, ans;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<pair<int, int> > A(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &A[i].first);
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    for (int j = 0; j < n; ++j) {
        ans = max(ans, A[j].second - j);
    }

    cout << ans + 1;

    return 0;
}