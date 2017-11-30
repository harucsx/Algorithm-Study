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

int n;

void hanoi(int n, int from, int to, int via){
    if (n == 1){
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(n-1, from, via, to);
    hanoi(1, from, to, via);
    hanoi(n-1, via, to, from);
}

int main() {
    ios::sync_with_stdio(false);
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    cout << (int) (pow(2,n) - 0.9) << '\n';

    hanoi(n, 1, 3, 2);
    return 0;
}
