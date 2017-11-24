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

bool cmp(const pair<pair<int, int>, string> &a, const pair<pair<int, int>, string> &b) {
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    else
        return a.first.first < b.first.first;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    vector<pair<pair<int, int>, string> > v;
    cin >> N;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(make_pair(age, i), name));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << v[i].first.first << " " << v[i].second << '\n';
    }
    return 0;
}
