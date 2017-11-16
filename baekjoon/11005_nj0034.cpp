#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

long long int n;
int b;
string ans;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> b;
    while (n > 0) {
        if (n % b >= 10) {
            ans += (char) (n % b - 10 + 'A');
        } else {
            ans += (char) (n % b + '0');
        }
        n /= b;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}