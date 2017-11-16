//
// Created by John on 2017-11-07.
//
#include <cstdio>
#include <iostream>

using namespace std;
string str;
int len;

int dp[5010];

bool isOneToSix(char letter) {
    if (letter == '1' || letter == '2' ||
        letter == '3' || letter == '4' || letter == '5' ||
        letter == '6')
        return true;
    return false;
}

void sol() {
    if(str[0] != '0')
        dp[0] = 1;
    else
        return;

    if(str[1] == '0' && !(str[0] == '1' || str[0] == '2')) {
        dp[1] = 0;
        return;
    }
    if (str[0] == '1' && str[1] != '0')
        dp[1] = dp[0] + 1;
    else if(str[0] == '1' && str[0] == '0')
        dp[1] = 1;
    else if (str[0] == '2' && isOneToSix(str[1]))
        dp[1] = dp[0] + 1;
    else if (str[0] == '2' && str[1] == '0')
        dp[1] = 1;
    else
        dp[1] = dp[0];

    for (int i = 2; i < len; ++i) {
        if(str[i] == '0' && !(str[i - 1] == '1' || str[i - 1] == '2')) {
            dp[i] = 0;
            return;
        }
        if (str[i - 1] == '1' && str[i] != '0')
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
        else if(str[i - 1] == '1' && str[i] == '0')
            dp[i] = dp[i - 2];
        else if (str[i - 1] == '2' && isOneToSix(str[i]))
            dp[i] = (dp[i - 1] + dp[i - 2] ) % 1000000;
        else if (str[i - 1] == '2' && str[i] == '0')
            dp[i] = (dp[i - 2] ) % 1000000;
        else
            dp[i] = dp[i - 1];
    }
}

int main() {
#ifdef JOHNDEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> str;
    len = str.length();
//    cout<<len<<endl;
    sol();
    cout << dp[len - 1];
}