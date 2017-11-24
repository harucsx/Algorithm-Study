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

bool cmp(const pair<long long int, int> &a, const pair<long long int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    vector<long long int> v;
    vector<pair<long long int, int> > l;
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long int now = v[0];
    int cont = 1;

    for (int i = 1; i < N; ++i) {
        if (now == v[i]) {
            cont++;
        } else {
            l.push_back(make_pair(now, cont));
            cont = 1;
            now = v[i];
        }
    }

    l.push_back(make_pair(now, cont));

    sort(l.begin(), l.end(), cmp);
    cout << l[0].first;
    return 0;
}
