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

int n, p, o, m, z, ans;

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        if (num[i] > 1) {
            p++;
        } else if(num[i] == 1){
            o++;
        } else if (num[i] < 0) {
            m++;
        } else {
            z++;
        }
    }
    sort(num.begin(), num.end());

    // 음수 ~ 0 까지 합
    if (m % 2 == 1) {
        if (z == 0) {
            ans += num[m - 1];
        }
        m--;
    }
    for (int j = 0; j < m; j += 2) {
        ans += num[j] * num[j + 1];
    }
    // 1 합
    ans += o;

    // 양수 합
    if (p % 2 == 1) {
        ans += num[n - p];
        p--;
    }
    for (int k = n - p; k < n; k += 2) {
        ans += num[k] * num[k + 1];
    }

    cout << ans;
    return 0;
}