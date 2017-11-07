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
    unsigned test_case;

    cin >> test_case;

    for (unsigned tc = 0; tc < test_case; ++tc) {
        unsigned N;
        vector<long long int> count;

        cin >> N;
        count.resize(N + 10);

        count[1] = 1;
        count[2] = 1;
        count[3] = 1;
        count[4] = 2;
        count[5] = 2;
        count[6] = 3;
        count[7] = 4;
        count[8] = 5;

        for (int i = 9; i <= N; ++i) {
            count[i] = count[i - 1] + count[i - 5];
        }

        cout << count[N] << '\n';
    }

    return 0;
}
