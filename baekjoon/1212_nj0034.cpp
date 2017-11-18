#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

string octa, bin;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> octa;
    reverse(octa.begin(), octa.end());
    for (int i = 0; i < octa.length(); i++) {
        for (int j = i * 3; j < i * 3 + 3; ++j) {
            bin += (char) ((octa[i] - '0') % 2 + '0');
            octa[i] = (char) ((octa[i] - '0') / 2 + '0');
        }
    }
    while (bin[bin.length() - 1] == '0' && bin.length() > 1) {
        bin.erase(bin.length() - 1, 1);
    }
    reverse(bin.begin(), bin.end());
    cout << bin;

    return 0;
}