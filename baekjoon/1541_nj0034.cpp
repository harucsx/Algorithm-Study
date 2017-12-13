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

int b, ans;
char pm;
bool m;

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &ans);
    while (scanf(" %c%d", &pm, &b) != -1) {
        if (pm == '-') {
            ans -= b;
            m = true;
        } else {
            if (m) {
                ans -= b;
            } else {
                ans += b;
            }
        }
    }

    cout << ans;

    return 0;
}