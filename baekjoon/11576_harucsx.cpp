#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int A, B, m;
    int normal = 0;
    int base = 1;
    vector<int> a;
    stack<int> b;

    cin >> A >> B >> m;
    a.resize(m);

    for (int i = 0; i < m; ++i)
        cin >> a[i];

    for (int i = m - 1; i >= 0; --i) {
        normal += a[i] * base;
        base *= A;
    }

    while (normal >= B) {
        b.push(normal % B);
        normal /= B;
    }

    b.push(normal);

    while (!b.empty()) {
        cout << b.top() << ' ';
        b.pop();
    }

    return 0;
}
