#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int x, y, ans;
int a[50][50], b[50][50];

void switch_array(int x, int y){
    for (int i = y; i < y+3; ++i) {
        for (int j = x; j < x+3; ++j) {
            a[j][i] = a[j][i] xor 1;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> y >> x;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            scanf(" %1d", &a[j][i]);
        }
    }
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            scanf(" %1d", &b[j][i]);
        }
    }

    for (int i = 0; i < y-2; ++i) {
        for (int j = 0; j < x-2; ++j) {
            if(a[j][i] != b[j][i]){
                switch_array(j, i);
                ans++;
            }
        }
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if(a[j][i] != b[j][i]){
                ans = -1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}