#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

long long int ans;
int b;
string n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> b;
    reverse(n.begin(), n.end());
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] >= 'A' && n[i] <= 'Z') {
            ans += pow(b, i) * (n[i] - 'A' + 10);
        } else {
            ans += pow(b, i) * (n[i] - '0');
        }
    }
    cout << ans;

    return 0;
}