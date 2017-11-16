#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

string code;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> code;
    vector<long long int> d;
    d.resize(code.length() + 1);
    d[0] = 1;
    if (code[0] == '0') {
        d[1] = 0;
    } else {
        d[1] = 1;
    }
    for (int i = 2; i <= code.length(); ++i) {
        if (((code[i - 2] == '0' || code[i - 2] >= '3') && code[i - 1] == '0') || d[i - 1] == 0) {
            d[i] = 0;
        } else if ((code[i - 2] == '1' && code[i - 1] >= '1') ||
                   code[i - 2] == '2' && code[i - 1] >= '1' && code[i - 1] <= '6') {
            d[i] = d[i - 1] + d[i - 2];
            d[i] %= 1000000;
        } else if ((code[i - 2] == '1' || code[i - 2] == '2') && code[i - 1] == '0') {
            d[i] = d[i - 2];
            d[i] %= 1000000;
        } else {
            d[i] = d[i - 1];
            d[i] %= 1000000;
        }
    }
    cout << d[code.length()] % 1000000;
    return 0;
}