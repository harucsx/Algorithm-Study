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

bool cmp(const pair<string, vector<int> > &a, const pair<string, vector<int> > &b) {
    bool result;
    if (a.second[0] != b.second[0])
        return a.second[0] > b.second[0];
    else if(a.second[1] != b.second[1])
        return a.second[1] < b.second[1];
    else if (a.second[2] != b.second[2])
        return a.second[2] > b.second[2];
    else
        return a.first < b.first;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    vector<pair<string, vector<int> > > v;
    cin >> N;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        vector<int> score;
        string name;
        score.resize(3);
        cin  >> name >> score[0] >> score[1] >> score[2];
        v.push_back(make_pair(name, score));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << '\n';
    }
    return 0;
}
