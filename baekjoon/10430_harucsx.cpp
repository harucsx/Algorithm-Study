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
    int A, B, C;
    cin >> A >> B >> C;

    cout << (A + B) % C << endl;
    cout << (A % C + B % C) % C << endl;
    cout << (A * B) % C << endl;
    cout << (A % C * B % C) % C << endl;
    return 0;
}
