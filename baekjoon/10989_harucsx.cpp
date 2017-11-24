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

int v[10001];

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        int in;
        scanf("%d", &in);
        v[in]++;
    }

    for (int i = 1; i <= 10000; ++i) {
        for (int t = 0; t < v[i]; ++t) {
            printf("%d\n", i);
        }
    }

    return 0;
}
