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
    string pw;
    vector<int> count;

    cin >> pw;
    count.resize(pw.size());
    count[0] = (pw[0] == '0') ? 0 : 1;

    for (int i = 1; i < pw.size(); ++i) {
        if (pw[i] == '0' && (pw[i - 1] > '2' || pw[i - 1] == '0')) {
            cout << 0;
            return 0;
        }

        count[i] += count[i - 1];

        if (pw[i] == '0' && (pw[i - 1] == '1' || pw[i - 1] == '2')) {
            count[i] = (i > 1) ? count[i - 2] : 1;
        } else if (pw[i - 1] == '1' || (pw[i - 1] == '2' && '0' < pw[i] && pw[i] <= '6')) {
            count[i] += (i > 1) ? count[i - 2] : 1;
        }

        count[i] %= 1000000;
    }

    cout << count[pw.size() - 1] % 1000000;

    return 0;
}
