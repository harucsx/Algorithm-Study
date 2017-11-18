#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;


void store(stack<char> &s, int n) {
    if (n < 10)
        s.push((char) (n + '0'));
    else
        s.push((char) (n - 10 + 'A'));
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int B;
    long long base = 1, result = 0;
    string s;
    cin >> s >> B;


    for (int i = (int) s.length() - 1; i >= 0; --i) {
        result += base * ((s[i] < 'A') ? s[i] - '0' : s[i] - 'A' + 10);
        base *= B;
    }

    cout << result;

    return 0;
}
