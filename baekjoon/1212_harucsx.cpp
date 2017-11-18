#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

string conv_to_2(int n, bool first) {
    switch (n) {
        case 0:
            return (first) ? "" : "000";
        case 1:
            return (first) ? "1" : "001";
        case 2:
            return (first) ? "10" : "010";
        case 3:
            return (first) ? "11" : "011";
        case 4:
            return "100";
        case 5:
            return "101";
        case 6:
            return "110";
        case 7:
            return "111";
    }
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;

    if (s == "0") {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < s.length(); ++i) {
        cout << conv_to_2((int) (s[i] - '0'), i == 0);
    }

    return 0;
}

