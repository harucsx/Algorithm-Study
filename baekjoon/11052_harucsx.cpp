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

    vector<int> price;
    price.resize(N + 1);

    vector<int> max_price;
    max_price.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> price[i];
    }

    max_price[1] = price[1];

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i - j < 0)
                break;

            max_price[i] = max(max_price[i], max_price[i - j] + price[j]);
        }
    }

    cout << max_price[N];
    return 0;
}
