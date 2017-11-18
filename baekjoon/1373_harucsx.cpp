#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

int conv2_8(int i1, int i2, int i3) {
    return 4 * i1 + 2 * i2 + i3;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    stack<int> p;
    string s;
    cin >> s;

    for (int i = (int) s.length() - 1; i >= 0; i -= 3) {
        int i1, i2, i3;
        i1 = (s[i - 2] == '0') ? 0 : 1;
        i2 = (s[i - 1] == '0') ? 0 : 1;
        i3 = (s[i] == '0') ? 0 : 1;

        if (i == 0) i1 = i2 = 0;
        if (i == 1) i1 = 0;

        p.push(conv2_8(i1, i2, i3));
    }

    /*
     *  0에 대한 대응 필요 (출력시 맨 처음 0은 거르고 출력)
     */
    while (!p.empty()) {
        cout << p.top();
        p.pop();
    }

    return 0;
}

