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
    vector<int> v;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    for(int i : v)
        cout << i << '\n';
    return 0;
}
