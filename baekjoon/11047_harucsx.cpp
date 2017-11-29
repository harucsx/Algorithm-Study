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

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, K;
    int result = 0;
    vector<int> A;
    cin >> N >> K;

    A.resize(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    for (int i = N; i > 0; --i) {
        if (i == 1 && K % A[1] != 0){
            cout << 0;
            break;
        }

        if (K < A[i]) continue;

        result += K / A[i];
        K %= A[i];
    }

    cout << result;
    return 0;
}
