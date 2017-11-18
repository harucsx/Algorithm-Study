#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

string bin, ans;
int data;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> bin;
    reverse(bin.begin(), bin.end());
    for (int i = 0; i < bin.length(); i += 3) {
        for (int j = 0; j < 3; ++j) {
            if (bin[i + j] == '0' || bin[i + j] == '1') {
                data += (bin[i + j] - '0') * pow(2, j);
            }
        }
        ans += (char) (data + '0');
        data = 0;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}