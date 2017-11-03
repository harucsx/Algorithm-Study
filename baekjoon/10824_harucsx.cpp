#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    string A, B, C, D;
    int num1, num2;

    cin >> A >> B >> C >> D;

    num1 = stoi(A + B);
    num2 = stoi(C + D);

    cout << num1 + num2;
    return 0;
}
