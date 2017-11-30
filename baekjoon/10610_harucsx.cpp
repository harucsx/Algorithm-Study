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
    vector<int> v;
    int result = 0;

    while (true) {
        char n = -1;
        cin >> n;

        if (n < 0) break;
        result += (int) (n - '0');
        v.push_back((int) (n - '0'));
    }

    sort(v.begin(), v.end(), greater<int>());

    if (v[v.size() - 1] > 0 || result % 3 > 0) {
        cout << -1;
    } else {
        for (int i = 0; i < v.size(); ++i) {
            printf("%d", v[i]);
        }
    }

    return 0;
}
