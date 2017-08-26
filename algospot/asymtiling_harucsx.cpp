/*
 *  개멍청하게 똑같은 계산 2번했음 수정 요망
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int rest_tile(int num, vector<int> &tile) {
    int target = num / 2;

    tile[1] = 1;
    tile[2] = 2;

    for (int i = 3; i <= target; ++i)
        tile[i] = (tile[i - 1] + tile[i - 2]) % 1000000007;

    tile[0] = 1;

    if (num % 2 == 0) {
        return tile[target] + tile[target - 1];
    } else {
        return tile[target];
    }
}

int full_tile(int num, vector<int> &tile) {
    tile[1] = 1;
    tile[2] = 2;

    for (int i = 3; i <= num; ++i)
        tile[i] = (tile[i - 1] + tile[i - 2]) % 1000000007;

    return tile[num];
}

int main(int argc, char **argv) {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int num, ans;
        vector<int> ftile, rtile;

        cin >> num;
        ftile.resize(num + 1);
        rtile.resize(num + 1);

        ans = full_tile(num, ftile) - rest_tile(num, rtile);
        ans = (ans < 0) ? ans + 1000000007 : ans;
        ans = (ans < 0) ? ans + 1000000007 : ans;
        cout << ans << '\n';

        ftile.resize(1);
        rtile.resize(1);
    }

    return 0;
}
