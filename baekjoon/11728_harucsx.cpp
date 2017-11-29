#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int A, B, ap = 0, bp = 0, rp = 0;
    vector<int> a, b, r;
    cin >> A >> B;
    a.resize(A);
    b.resize(B);
    r.resize(A + B);

    for (int i = 0; i < A; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < B; ++i) {
        cin >> b[i];
    }

    while (ap < A && bp < B) {
        if (a[ap] < b[bp]) {
            r[rp++] = a[ap++];
        } else {
            r[rp++] = b[bp++];
        }
    }

    while(ap < A){
        r[rp++] = a[ap++];
    }

    while(bp < B){
        r[rp++] = b[bp++];
    }

    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << ' ';
    }

    return 0;
}
