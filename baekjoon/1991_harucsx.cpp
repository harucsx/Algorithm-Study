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

int N;
char node[27][2];

void preorder(int n) {
    if (n < 1 || n > 26) return;

    cout << (char) (n + 'A' - 1);
    preorder(node[n][0]);
    preorder(node[n][1]);
}

void inorder(int n) {
    if (n < 1 || n > 26) return;

    inorder(node[n][0]);
    cout << (char) (n + 'A' - 1);
    inorder(node[n][1]);
}

void postorder(int n) {
    if (n < 1 || n > 26) return;

    postorder(node[n][0]);
    postorder(node[n][1]);
    cout << (char) (n + 'A' - 1);
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char P, L, R;
        int now;
        cin >> P >> L >> R;
        now = P - 'A' + 1;
        if (L != '.') node[now][0] = (char) (L - 'A' + 1);
        if (R != '.') node[now][1] = (char) (R - 'A' + 1);
    }

    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);
    cout << endl;

    return 0;
}
