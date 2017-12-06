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

int n, num, cnt[10001];

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf(" %d", &num);
		cnt[num]++;
	}
	for (int j = 1; j <= 10000; ++j) {
		while (cnt[j]) {
			printf("%d\n", j);
			cnt[j]--;
		}
	}
	return 0;
}