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

int n, next, ans;

bool cmp(pair<int, int> u, pair<int, int> v) {
	if (u.second < v.second) {
		return true;
	} else if (u.second == v.second) {
		return u.first < v.first;
	} else {
		return false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	vector<pair<int, int> > conf(n);
	for (int i = 0; i < n; ++i) {
		cin >> conf[i].first >> conf[i].second;
	}

	sort(conf.begin(), conf.end(), cmp);
	for (int k = 0; k < n; ++k) {
	}

	for (int j = 0; j < n; ++j) {
		if (conf[j].first >= next) {
			next = conf[j].second;
			ans++;
//            cout << conf[j].first << " " << conf[j].second << endl;
		}
	}

	cout << ans;
	return 0;
}