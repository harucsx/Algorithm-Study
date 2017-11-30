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
    char src[50][50], dest[50][50];
    int N, M, result = 0;
    bool same = true;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> src[j][i];
            src[j][i] -= '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> dest[j][i];
            dest[j][i] -= '0';
        }
    }

    for (int i = 0; i < N - 2; ++i) {
        for (int j = 0; j < M - 2; ++j) {
            if (src[j][i] != dest[j][i]) {
                result++;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        src[j + y][i + x] = !src[j + y][i + x];
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (src[j][i] != dest[j][i]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    cout << ((same) ? result : -1);
    return 0;
}
