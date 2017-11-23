#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int n, p;
bool data[10000001];
int prime[10000000];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 1) {
        cout << '\n';
    } else {
        data[1] = true;
        for (int j = 2; j * j <= n; ++j) {
            if (data[j]) {
                continue;
            }
            for (int k = 0; j * (j + k) <= n; ++k) {
                data[j * (j + k)] = true;
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (!data[i]) {
                prime[p] = i;
                p++;
            }
        }
        p = 0;
        while (n != 1) {
            if (n % prime[p] == 0) {
                cout << prime[p] << '\n';
                n /= prime[p];
            } else {
                p++;
            }
        }
    }
    return 0;
}