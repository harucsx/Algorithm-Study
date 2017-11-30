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
    int N;
    int result = -1;
    vector<pair<int, int> > v;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int in;
        cin >> in;
        v.push_back(make_pair(in, i));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        result = max(result, v[i].second - i + 1);
    }

    cout << result;
    return 0;
}
