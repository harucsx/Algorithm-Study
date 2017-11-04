#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;

    long long int count[100][2];
    long long int result = 0;

    count[1][0] = 0;
    count[1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        count[i][0] = count[i-1][0] + count[i-1][1];
        count[i][1] = count[i-1][0];
    }

    result = count[N][0] + count[N][1];

    cout << result;
    return 0;
}
