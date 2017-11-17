#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, n2 = 0, n5 = 0;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int result = i;

        while(result % 2 == 0){
            result /= 2;
            n2++;
        }

        while(result % 5 == 0){
            result /= 5;
            n5++;
        }
    }

    cout << min(n2, n5);
    return 0;
}
