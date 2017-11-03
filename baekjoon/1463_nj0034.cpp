

#include <iostream>
#include <cstdio>

using namespace std;

int N;

int make1(int n, int *array) {
    if (n == 1) {
        return 0;
    }
    if (array[n]) {
        return array[n];
    }
    array[n] = make1(n - 1, array) + 1;

    if ((n % 3) == 0) {
        array[n] = min(array[n], make1(n / 3, array) + 1);
    }
    if ((n % 2) == 0) {
        array[n] = min(array[n], make1(n / 2, array) + 1);
    }
    return array[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N;
    int *array = new int[N + 1]();
    cout << make1(N, array);
    delete[] array;
    return 0;
}
