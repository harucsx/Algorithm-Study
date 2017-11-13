//
// Created by John on 2017-11-07.
//

#include <iostream>
#include <cstdio>

using namespace std;

long long int dp[210][210]; //n k

int n;
int k;

void sol() {
    for (int i = 0; i <= 200; ++i) {
        dp[i][1] = 1;
        dp[i][2] = i + 1;

        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) { //n
        for (int j = 3; j <= k; ++j) { //k
            for (int l = 0; l <= i; ++l) {
                dp[i][j] += dp[i - l][j - 1];
                dp[i][j] %= 1000000000;
            }
        }
    }
}

int main() {
#ifdef JOHNDEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    sol();
    cout<<dp[n][k];

}