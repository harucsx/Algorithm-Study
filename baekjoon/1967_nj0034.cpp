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

int n, node1, node2, dis, max_dis, max_node;
// <node, distance>
vector<pair<int, int> > a[100001];
bool check[100001];

void dfs(int n, int d) {
	check[n] = true;
	if (d > max_dis) {
		max_dis = d;
		max_node = n;
	}
	for (int i = 0; i < a[n].size(); ++i) {
		if (!check[a[n][i].first]) {
			dfs(a[n][i].first, d + a[n][i].second);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &node1, &node2, &dis);
		a[node1].push_back(make_pair(node2, dis));
		a[node2].push_back(make_pair(node1, dis));
	}
	dfs(1, 0);
	max_dis = 0;
	memset(check, false, sizeof(check));
	dfs(max_node, 0);
	cout << max_dis;
	return 0;
}