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
    int N, B;
    stack<char> s;
    cin >> N >> B;

    while (N >= B) {
        store(s, N % B);
        N /= B;
    }

    store(s, N);

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}
