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

int n, check = 2, a[27][27];
vector<int> ans;
string input;

void dfs(int x, int y) {
    if (a[x][y] == 0 || a[x][y] > 1) {
        return;
    }
    a[x][y] = check;
    check++;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> input;
        for (int j = 1; j <= n; ++j) {
            a[j][i] = (input[j - 1] - '0');
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dfs(j, i);
            if (check > 2) {
                ans.push_back(check - 2);
                check = 2;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int k = 0; k < ans.size(); ++k) {
        printf("%d\n", ans[k]);
    }

    return 0;
}