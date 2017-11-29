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
    bool minus = false;
    char op;
    int result, num;

    cin >> num;
    result = num;

    while (true) {
        op = -1;
        cin >> op;

        if (op == '-') minus = true;
        if (op < 0) break;
        cin >> num;

        if (minus)
            result -= num;
        else
            result += num;
    }

    cout << result;
    return 0;
}
