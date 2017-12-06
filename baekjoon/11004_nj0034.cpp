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

int n, k;
int num[5000000];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &num[i]);
    }
    nth_element(num, num + k-1, num + n);
    cout << num[k-1];
    return 0;
}