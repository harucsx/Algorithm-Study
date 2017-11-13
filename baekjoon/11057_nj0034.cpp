#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
long long int stair[1001][11];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N;
    stair[1][10] = 10;
    for (int i = 0; i < 10; ++i) {
        stair[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < j + 1; ++k) {
                stair[i][j] += stair[i - 1][k] % 10007;
            }
        }
        for (int k = 0; k < 10; ++k) {
            stair[i][10] += stair[i][k] % 10007;
        }
    }
    cout << stair[N][10] % 10007;
    return 0;
}



