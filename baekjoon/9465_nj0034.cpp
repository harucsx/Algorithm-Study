#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n1, n2;
int board[2][100001];
int m[3][100001];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> n2;
        for (int k = 0; k < 2; ++k) {
            for (int j = 0; j < n2; ++j) {
                cin >> board[k][j];
            }
        }
        m[0][1] = board[0][0];
        m[1][1] = board[1][0];
        m[2][1] = max(m[0][1], m[1][1]);
        for (int l = 2; l <= n2; ++l) {
            m[0][l] = max(m[1][l-2], m[1][l-1]) + board[0][l-1];
            m[1][l] = max(m[0][l-2], m[0][l-1]) + board[1][l-1];
            m[2][l] = max(m[0][l], m[1][l]);
        }
        cout << m[2][n2] << endl;
    }

    return 0;
}