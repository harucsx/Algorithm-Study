//
// Created by John on 2017-10-23.
//

#include <iostream>

int dp[40];
int n;

using namespace std;

void sol() {
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 3 * 3 + 2;
    for (int i = 6; i <= n; ++i) {
        if (i % 2 == 0) {
            dp[i] = dp[i - 2] * 3;
            for (int j = 2; j * 2 <= i; ++j) {
                dp[i] = dp[i] + 2 * dp[i - 2 * j];
            }


        } else
            dp[i] = 0;
    }
}

int main() {
    cin >> n;

    sol();

    cout << dp[n] << endl;
}