#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>

using namespace std;

void fact(long long int end, int *n2, int *n5) {
    long long int base = 2;
    while(base <= end){
        *n2 += end / base;
        base *= 2;
    }

    base = 5;
    while(base <= end){
        *n5 += end / base;
        base *= 5;
    }
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M;
    int n2p = 0, n5p = 0;
    int n2n = 0, n5n = 0;

    cin >> N >> M;

    fact(N, &n2p, &n5p);
    fact(M, &n2n, &n5n);
    fact(N - M, &n2n, &n5n);

    cout << min(n2p - n2n, n5p - n5n);

    return 0;
}
