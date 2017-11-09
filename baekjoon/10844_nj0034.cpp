#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
long long int stair[101][11];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N;
    stair[1][10] = 9;
    stair[1][0] = 0;
    for (int i = 1; i < 10; ++i) {
        stair[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        stair[i][0] = stair[i - 1][1] % 1000000000;
        stair[i][9] = stair[i - 1][8] % 1000000000;
        for (int j = 1; j < 9; ++j) {
            stair[i][j] = stair[i - 1][j - 1] % 1000000000 + stair[i - 1][j + 1] % 1000000000;
        }
        for (int k = 0; k < 10; ++k) {
            stair[i][10] += stair[i][k] % 1000000000;
        }
    }
    cout << stair[N][10] % 1000000000;
    return 0;
}



