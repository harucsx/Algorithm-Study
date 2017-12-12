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

int n, t, ans;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());

	for (int j = 0; j < n; ++j) {
		t = t + p[j];
		ans += t;
	}
	cout << ans;
	return 0;
}