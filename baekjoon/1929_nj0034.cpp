#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int m, n;
bool data[1000001];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> m >> n;
    data[1] = true;
    for (int j = 2; j <= sqrt(n); ++j) {
        if(data[j]){
            continue;
        }
        for (int k = 0; j * (j + k) <= n; ++k) {
            data[j * (j + k)] = true;
        }
    }
    for (int l = m; l <= n; ++l) {
        if(!data[l]){
            cout << l << '\n';
        }
    }
    return 0;
}