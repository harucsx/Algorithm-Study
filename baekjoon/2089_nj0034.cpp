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
string mbin;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 0) {
        mbin.push_back('0');
    } else {
        while (n != 0) {
            if (n % 2 == 0) {
                mbin += '0';
                n /= -2;
            } else {
                mbin += '1';
                if (n > 0) {
                    n /= -2;
                } else {
                    n /= -2;
                    n += 1;
                }
            }
        }
    }
    reverse(mbin.begin(), mbin.end());
    cout << mbin;
    return 0;
}