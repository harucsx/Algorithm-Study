#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<pair<int, int> > pos(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &pos[i].second, &pos[i].first);
    }
    sort(pos.begin(), pos.end());
    for (int j = 0; j < n; ++j) {
        printf("%d %d\n", pos[j].second, pos[j].first);
    }

    return 0;
}