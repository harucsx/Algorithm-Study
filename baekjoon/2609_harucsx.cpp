#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int gcd(int a, int b) {
    return (a%b == 0) ? b : gcd(b, a % b);
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int A, B;
    cin >> A >> B;

    int G = gcd(A, B);

    cout << G << endl;
    cout << A * B / G << endl;
    return 0;
}
