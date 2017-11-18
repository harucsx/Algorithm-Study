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
    int N, B;
    stack<int> s;
    cin >> N;
    B = -2;

    if (N == 0){
        cout << 0;
        return 0;
    }

    while (N) {
        if (N % B >= 0) {
            s.push(N % B);
            N /= B;
        } else {
            s.push(N % B + 2);
            N /= B;
            N++;
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
