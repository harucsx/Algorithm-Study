#include <iostream>
#include <string.h>

using namespace std;

char A[10], B[10], C[10], D[10];
string a, b;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> A >> B >> C >> D;
    a.append(A).append(B);
    b.append(C).append(D);
    cout << stoll(a) + stoll(b);
    return 0;
}