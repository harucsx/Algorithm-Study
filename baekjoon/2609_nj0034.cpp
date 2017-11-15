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
int x, y;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> a >> b;
    x = a;
    y = b;
    while (true){
        c = a % b;
        if(c == 0){
            break;
        }
        a = b;
        b = c;
    }
    cout << b << endl << x * y / b;
    return 0;
}