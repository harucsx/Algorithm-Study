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

bool cmp(const pair<long long int, long long int> &a, const pair<long long int, long long int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    int result = 0;
    vector<pair<long long int, long long int> > v;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        long long int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), cmp);

    long long int now = -1;

    for (int i = 0; i < v.size(); ++i) {
        if (now <= v[i].first) {
            result++;
            now = v[i].second;
        }
    }

    cout << result;
    return 0;
}
