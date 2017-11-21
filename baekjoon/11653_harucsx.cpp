#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;

    cin >> N;

    for (int i = 2; i <= N; ++i) {
        while (N % i == 0){
            cout << i << '\n';
            N /= i;
        }

        if (N < i)
            break;
    }

    return 0;
}