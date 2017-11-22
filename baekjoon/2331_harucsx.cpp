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

using namespace std;

int next_n[360000];

int get_next(int n, int p) {
    const char *number = to_string(n).c_str();
    int len = strlen(number);
    int result = 0;

    for (int i = 0; i < len; ++i)
        result += (int) pow((double) (number[i] - '0'), p);

    return result;
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int A, P, V;
    int result = 0;
    int last_value;
    cin >> A >> P;

    V = A;

    while (true) {
        int next_value = get_next(V, P);

        if (!next_n[V]) {
            next_n[V] = next_value;
        } else {
            last_value = V;
            break;
        }

        V = next_value;
    }

    while (A != last_value) {
        A = next_n[A];
        result++;
    }

    cout << result;

    return 0;
}
