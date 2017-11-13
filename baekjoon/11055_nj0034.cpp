#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> d, m;
    d.resize(n + 1);
    m.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int j = 1; j <= n; ++j) {
        m[j] = d[j];
        for (int k = 1; k < j; ++k) {
            if(d[k] < d[j]){
                m[j] = max(m[j], m[k] + d[j]);
            }
        }
    }
    cout << *max_element(m.begin(),m.end());
    return 0;
}