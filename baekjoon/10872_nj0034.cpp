#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

long long int ans;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    ans = n;
    if (n == 0) {
        ans = 1;
    } else {
        for (int i = 1; i < n; ++i) {
            ans *= n - i;
        }
    }
    cout << ans;

    return 0;
}