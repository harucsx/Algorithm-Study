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
#include <sstream>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    int result = 0;
    vector<int> v;

    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int now = 0;

    for (int i = 0; i < v.size(); ++i) {
        now += v[i];
        result += now;
    }

    cout << result;
    return 0;
}
