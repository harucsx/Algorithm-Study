#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> d;
    cin >> N;
    d.resize(N + 1);
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i < N + 1; ++i) {
        d[i] = d[i - 1]%10007 + d[i - 2]%10007;
    }
    cout << d[N] % 10007;
    return 0;
}
