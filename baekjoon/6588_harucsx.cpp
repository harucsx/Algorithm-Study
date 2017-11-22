#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int prime[1000010];
    int num = 0, N = 1000000;
    // 소수 0, 소수 아님 1
    prime[1] = 1;

    int last_search = (int) sqrt(N);
    for (int i = 2; i <= last_search + 1; ++i) {
        for (int j = 1; i * j <= N; ++j) {
            if (j > 1 && i * j < 1000000)
                prime[i * j] = 1;
        }
    }

    do {
        scanf("%d", &num);
        if (!num) break;

        bool found = false;
        for (int i = 3; i <= num / 2; i += 2) {
            if (!prime[i] && !prime[num - i]) {
                printf("%d = %d + %d\n", num, i, num - i);
                found = true;
                break;
            }
        }

        if (!found)
            printf("Goldbach's conjecture is wrong.\n");

    } while (num);

    return 0;
}
