//
// Created by John on 2017-02-22.
//

#include <iostream>

using namespace std;

int findSol(int x, int y, int matrix[100][100], int size) {

    if(x == size - 1 && y == size - 1) return 1;
    if(x < 0 || x >= size || y < 0 || y >= size) return 0;

    int num = matrix[x][y];
    if(num == -1) return 0;
    matrix[x][y] = -1;

    if(findSol(x + num, y, matrix, size)) return 1;
    if(findSol(x, y + num, matrix, size)) return 1;

    return 0;
}

int main() {
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        int num;
        cin>>num;
        int matrix[100][100];
        for (int j = 0; j < num; ++j) {
            for (int k = 0; k < num; ++k) {
                cin>>matrix[j][k];
            }
        }
        int sol;
        sol = findSol(0, 0, matrix, num);
        if(sol)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}