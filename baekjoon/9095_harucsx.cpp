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

    for (int i = 0; i < N; ++i) {
        int num;
        vector<int> v;
        cin >> num;

        v.resize(num + 1);
        v[1] = 1;
        v[2] = 2;
        v[3] = 4;

        for (int j = 4; j <= num; ++j) {
            v[j] = v[j-1] + v[j-2] + v[j-3];
        }

        cout << v[num] << '\n';
    }

    return 0;
}
