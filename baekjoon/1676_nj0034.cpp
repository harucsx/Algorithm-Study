#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int n, tmp, two, five;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 0) {
        cout << 0;
    } else {
        for (int i = 0; i < n; ++i) {
            tmp = n - i;
            while (tmp % 2 == 0) {
                two++;
                tmp /= 2;
            }
            tmp = n - i;
            while (tmp % 5 == 0) {
                five++;
                tmp /= 5;
            }
        }
        cout << min(two, five);
    }
    return 0;
}