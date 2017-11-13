//
// Created by John on 2017-11-07.
//

#include <iostream>
#include <cstdio>

using namespace std;

long long int dp[110];

int n;
int T;

void sol() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    for (int i = 9; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

}

int main() {
#ifdef JOHNDEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n;
        sol();
        cout << dp[n] << "\n";
    }

}