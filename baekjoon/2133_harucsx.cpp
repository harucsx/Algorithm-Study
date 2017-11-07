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
    unsigned N;
    vector<int> count;


    cin >> N;

    if (N % 2 == 1) {
        cout << 0;
        return 0;
    }

    count.resize(N + 1);

    count[0] = 1;
    count[2] = 3;

    for (int i = 4; i <= N; i += 2) {
        count[i] = count[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            count[i] += count[j] * 2;
        }
    }

    cout << count[N];
    return 0;
}
