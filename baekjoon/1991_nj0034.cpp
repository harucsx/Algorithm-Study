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

int n;
char root, l_child, r_child;

void pre(vector<int> *a, int root) {
    cout << (char) (root + 'A');
    if (a[root][0]) {
        pre(a, a[root][0]);
    }
    if (a[root][1]) {
        pre(a, a[root][1]);
    }
}

void in(vector<int> *a, int root) {
    if (a[root][0]) {
        in(a, a[root][0]);
    }
    cout << (char) (root + 'A');
    if (a[root][1]) {
        in(a, a[root][1]);
    }
}

void post(vector<int> *a, int root) {
    if (a[root][0]) {
        post(a, a[root][0]);
    }
    if (a[root][1]) {
        post(a, a[root][1]);
    }
    cout << (char) (root + 'A');
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> root >> l_child >> r_child;
        if (l_child == '.') {
            a[root - 'A'].push_back(0);
        } else {
            a[root - 'A'].push_back(l_child - 'A');
        }
        if (r_child == '.') {
            a[root - 'A'].push_back(0);
        } else {
            a[root - 'A'].push_back(r_child - 'A');
        }
    }
    pre(a, 0);
    cout << '\n';
    in(a, 0);
    cout << '\n';
    post(a, 0);

    return 0;
}