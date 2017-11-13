//
// Created by John on 2017-11-09.
//
#include <iostream>
#include <cstdio>
#include <cmath>

int n;

int dp[100000];

using namespace std;

void sol() {
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0x7fffffff;

        for (int j = 1; j <= sqrt(i); ++j) {
            dp[j*j] = 1;
            if(dp[j * j] + dp[i - j*j] < dp[i])
                dp[i] = dp[j * j] + dp[i - j*j];
        }
    }
}

int main() {
#ifdef JOHNDEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;

//    cout<<len<<endl;
    sol();
    cout << dp[n];
}