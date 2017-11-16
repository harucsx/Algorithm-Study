//
// Created by John on 2017-10-17.
//

#include <iostream>

using namespace std;

int n;

int arr[20][2];
int maxi = 0;

void sol(int index, int sum, int remain) {
    if (index >= n) {
        if (sum >= maxi && remain <= 0)
            maxi = sum;
        return;
    }
    if (remain <= 0)
        sol(index + 1, sum + arr[index][1], arr[index][0] - 1);
    sol(index + 1, sum, remain - 1);

}

int main() {
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sol(0, 0, 0);

    cout << maxi << endl;
}