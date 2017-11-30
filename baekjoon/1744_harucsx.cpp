#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long int result = 0;
    bool has_zero = false;
    vector<long long int> p, n, z;
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int in;
        cin >> in;

        if (in == 0)
            has_zero = true;

        if (in > 1)
            p.push_back(in);
        else if (in < 0)
            n.push_back(in);
        else
            z.push_back(in);
    }

    sort(p.begin(), p.end(), greater<long long int>());
    sort(n.begin(), n.end());

    for (int i = 1; i < p.size(); i += 2) {
        p[i] *= p[i - 1];
        p[i - 1] = 0;
    }

    for (int i = 1; i < n.size(); i += 2) {
        n[i] *= n[i - 1];
        n[i - 1] = 0;
    }
    if (n.size() % 2 == 1 && has_zero)
        n[n.size() - 1] = 0;

    for (int i = 0; i < p.size(); ++i)
        result += p[i];

    for (int i = 0; i < n.size(); ++i)
        result += n[i];

    for (int i = 0; i < z.size(); ++i)
        result += z[i];

    cout << result;
    return 0;
}
