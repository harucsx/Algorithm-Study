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

int s, i;
char value[100000];
bool zero;

int main() {
    freopen("input.txt", "r", stdin);
    while (scanf(" %c", &value[i]) != -1) {
        if (value[i] - '0' == 0) {
            zero = true;
        } else if ((value[i] - '0') % 3 > 0) {
            s += value[i] - '0';
        }
        i++;
    }
    sort(value, value + i);

    if (!zero || s % 3 > 0) {
        printf("-1");
    } else {
        for (int j = i - 1; j >= 0; --j) {
            printf("%d", value[j] - '0');
        }
    }
    return 0;
}