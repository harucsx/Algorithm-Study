#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int n, data, ans;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        if(data == 1){
            continue;
        }
        for (int j = 2; j < data; ++j) {
            if (data % j == 0) {
                ans--;
                break;
            }
        }
        ans++;
    }
    cout << ans;
    return 0;
}