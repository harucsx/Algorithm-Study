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

int v, e, test;
int n1, n2;
bool check[20001], team[20001], brk;
vector<int> a[20001];

int dfs(int n) {
    stack<int> s;
    s.push(n);
    check[n] = true;
    team[n] = true;
    while (!s.empty()) {
        int t = s.top();
        brk = false;
        for (int i = 0; i < a[t].size(); ++i) {
            if (check[a[t][i]] && team[t] == team[a[t][i]]) {
                return 0;
            }
            if (!check[a[t][i]]) {
                check[a[t][i]] = true;
                team[a[t][i]] = !team[t];
                s.push(a[t][i]);
                brk = true;
                break;

            }
        }
        if (!brk) {
            s.pop();
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> test;
    for (int i = 0; i < test; ++i) {
        cin >> v >> e;
        for (int j = 0; j < e; ++j) {
            cin >> n1 >> n2;
            a[n1].push_back(n2);
            a[n2].push_back(n1);
        }
        for (int k = 1; k <= v; ++k) {
            brk = false;
            if(!check[k]){
                if(dfs(k) == 0){
                    cout << "NO\n";
                    brk = true;
                    break;
                }
            }
        }
        if(!brk){
            cout << "YES\n";
        }
        for (int l = 1; l <= v; ++l) {
            a[l].clear();
        }
        memset(check, false, sizeof(check));
        memset(team, false, sizeof(team));
    }

    return 0;
}