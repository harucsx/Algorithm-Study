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

int A, P, i, ans = -1;
vector<int> a;

int mul(int n) {
    int sum = 0;
    for (int i = 0; i < 6; ++i) {
        int a = 1;
        int b = n % 10;
        for (int j = 0; j < P; ++j) {
            a *= b;
        }
        sum += a;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> A >> P;
    a.push_back(A);
    while (ans == -1) {
        a.push_back(mul(a[i]));
//        cout << a[i] << " ";
        i++;
        for (int j = 0; j < i; ++j) {
            if (a[j] == a[i]) {
                ans = j;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}