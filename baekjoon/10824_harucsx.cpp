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
    string A, B, C, D;
    cin >> A >> B >> C >> D;

    A += B;
    C += D;

    cout << (atoll(A.c_str()) + atoll(C.c_str()));
    return 0;
}
