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

int n, k, ans;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	vector<int> money(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &money[n - i - 1]);
	}
	for (int j = 0; j < n; ++j) {
		if (!k) {
			break;
		}
		while (k >= money[j]) {
			k -= money[j];
			ans++;
		}
	}
	cout << ans;
	return 0;
}