//
// Created by John on 2017-11-13.
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int result = -1;
int n;
vector<int> arr;
vector<int> dp;

void sol(int index) {
    if (index == n)
        return;

    for (int i = index - 1; i >= 0; --i) {
        if (arr[index] < arr[i]) {
            if (dp[index] < dp[i] + 1)
                dp[index] = dp[i] + 1;
        }
    }
    if(dp[index] == 0)
        dp[index] = 1;

    sol(index + 1);
}

int main() {
#ifdef JOHNDEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0] = 1;
    sol(1);

    for (int j = 0; j < n; ++j) {
        if (dp[j] > result)
            result = dp[j];
    }

    cout << result << endl;
    return 0;
}