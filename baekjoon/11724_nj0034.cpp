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

int v, e, connect;
int n1, n2;
bool check[1001], brk;
vector<int> a[1001];

void dfs(int n) {
    stack<int> s;
    s.push(n);
    while (!s.empty()) {
        int t = s.top();
        check[n] = true;
        brk = false;
        for (int i = 0; i < a[t].size(); ++i) {
            if (!check[a[t][i]]) {
                check[a[t][i]] = true;
                s.push(a[t][i]);
                brk = true;
                break;
            }
        }
        if (!brk) {
            s.pop();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        cin >> n1 >> n2;
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }
    for (int j = 1; j <= v; ++j) {
        if (!check[j]) {
            dfs(j);
            connect++;
        }
    }
    cout << connect;

    return 0;
}