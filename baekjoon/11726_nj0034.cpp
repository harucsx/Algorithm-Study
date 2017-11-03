#include <iostream>

using namespace std;

int N;

int dp(int n) {
    if (n <= 2) {
        return n;
    } else {
        return dp(n - 1) + dp(n - 2);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N;
    cout << (dp(N)) % 1007;

    return 0;
}