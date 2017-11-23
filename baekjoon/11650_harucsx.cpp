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

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    vector<pair<int, int> > v;
    cin >> N;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}
