#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int n, a, b, c, x, y;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        x = a;
        y = b;
        while (true) {
            c = a % b;
            if (c == 0) {
                break;
            }
            a = b;
            b = c;
        }
        cout << x * y / b << endl;
    }
    return 0;
}