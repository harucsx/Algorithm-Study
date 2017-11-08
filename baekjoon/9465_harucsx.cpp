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
    int test_case;

    cin >> test_case;

    for (int TC = 0; TC < test_case; ++TC) {
        int N;
        int score[100001][2];
        int max_value[100001][2];

        cin >> N;

        for (int i = 1; i <= N; ++i)
            cin >> score[i][0];

        for (int i = 1; i <= N; ++i)
            cin >> score[i][1];

        max_value[0][0] = 0;
        max_value[0][1] = 0;
        max_value[1][0] = score[1][0];
        max_value[1][1] = score[1][1];

        for (int i = 2; i <= N; ++i) {
            max_value[i][0] = max(max_value[i - 1][1], max(max_value[i - 2][0], max_value[i - 2][1])) + score[i][0];
            max_value[i][1] = max(max_value[i - 1][0], max(max_value[i - 2][0], max_value[i - 2][1])) + score[i][1];
        }

        cout << max(max_value[N][0], max_value[N][1]) << '\n';
    }
    return 0;
}
