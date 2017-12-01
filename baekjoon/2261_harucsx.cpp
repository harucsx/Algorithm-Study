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

int N;
vector<pair<int, int> > points;

int dist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int find_points(int start, int end) {
    if (start > end) return INT_MAX;
    int mid = (start + end) / 2;
    int left_min = find_points(start, mid - 1);
    int right_min = find_points(mid + 1, end);
    int local_min = min(left_min, right_min);

    int x = points[mid].first;
    int y = points[mid].second;

    if (mid <= end)
        for (int seek = mid + 1;
             seek <= N - 1 && (points[seek].first - x) * (points[seek].first - x) < local_min; ++seek) {
            local_min = min(local_min, dist(x, y, points[seek].first, points[seek].second));
        }

    if (start <= mid)
        for (int seek = mid - 1; seek >= 0 && (x - points[seek].first) * (x - points[seek].first) < local_min; --seek) {
            local_min = min(local_min, dist(x, y, points[seek].first, points[seek].second));
        }

    return local_min;
}

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(make_pair(x, y));
    }

    sort(points.begin(), points.end());
    cout << find_points(0, N - 1);
    return 0;
}
