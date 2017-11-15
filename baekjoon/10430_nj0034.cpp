#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int a, b, c;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> a >> b >> c;
    cout << (a + b) % c << endl;
    cout << (a % c + b % c) % c << endl;
    cout << (a * b) % c << endl;
    cout << (a % c * b % c) % c << endl;

    return 0;
}