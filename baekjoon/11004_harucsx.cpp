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

int v[5000000];

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    nth_element(v, v + --K, v + N);

    printf("%d", v[K]);
    return 0;
}
