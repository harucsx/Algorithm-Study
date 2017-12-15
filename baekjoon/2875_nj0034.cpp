#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int girl, boy, out;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> girl >> boy >> out;
    if (girl == 0 || boy == 0) {
        cout << 0;
        return 0;
    }
    if (girl > boy * 2) {
        while (girl != boy * 2) {
            if (out == 0) {
                cout << boy;
                return 0;
            }
            girl--;
            out--;
        }
    } else if (girl < boy * 2) {
        if(girl % 2 == 1){
            girl--;
            out--;
        }
        while (girl != boy * 2) {
            if (out == 0) {
                cout << girl / 2;
                return 0;
            }
            boy--;
            out--;
        }
    }
    if (out == 0) {
        cout << boy;
        return 0;
    }

    if ((out - 1) / 3 + 1 >= boy) {
        cout << 0;
    } else {
        cout << boy - ((out - 1) / 3 + 1);
    }

    return 0;
}