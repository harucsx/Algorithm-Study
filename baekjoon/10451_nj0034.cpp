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

int test, v, cycle;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> test;
    for (int t = 0; t < test; ++t) {
        cin >> v;
        vector<int> a(v + 1);
        vector<bool> check(v + 1);
        for (int i = 1; i <= v; ++i) {
            cin >> a[i];
        }
        for (int j = 1; j <= v; ++j) {
            if (check[j]) {
                continue;
            }
            int tmp = j;
            while (true) {
                check[tmp] = true;
                if (a[tmp] == j) {
                    break;
                } else {
                    tmp = a[tmp];
                }
            }
            cycle++;
        }
        cout << cycle << '\n';
        cycle = 0;
        check.clear();
    }
    return 0;
}