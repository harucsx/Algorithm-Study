//
// Created by John on 2017-02-23.
//

#include <iostream>

using namespace std;

int move_x[2] = {1, 1};
int move_y[2] = {0, 1};

void findSol(int x, int y, int map[100][100], int sum[100][100], int size) {
    if(x >= size) return;
    if(x == size -1) return;

    int current = sum[x][y];

    for (int i = 0; i < 2; ++i) {
        if(sum[x + move_x[i]][y + move_y[i]] < current + map[x + move_x[i]][y + move_y[i]]) {
            sum[x + move_x[i]][y + move_y[i]] = current + map[x + move_x[i]][y + move_y[i]];
            findSol(x + move_x[i], y + move_y[i], map, sum, size);
        }
    }
    return;
}

int main() {
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        int size;
        cin>>size;
        int map[100][100];
        int sum[100][100] = {0, };
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < j + 1; ++k) {
                cin>>map[j][k];
            }
        }
        sum[0][0] = map[0][0];
        findSol(0, 0, map, sum, size);
        int sol = 0;
        for (int l = 0; l < size; ++l) {
            if(sol < sum[size - 1][l]) sol = sum[size - 1][l];
        }
        cout<<sol<<endl;
    }
}
