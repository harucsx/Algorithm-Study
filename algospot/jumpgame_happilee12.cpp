//
// Created by HANLEEKYEUNG on 2017. 2. 2..
//

#include<iostream>
#define FOR(i, n) for(i = 0; i<n; i++)
using namespace std;

void searchBoard(int solve[100][100], int board[100][100], int size){
    solve[0][0] = 1;
    int i, j;
    FOR(i, size){
        FOR(j, size){
            if(solve[i][j]){
                int move = board[i][j];
                //right
                if(j+move < size) solve[i][j+move] = 1;
                //down
                if(i+move < size) solve[i+move][j] = 1;
            }
        }
    }
    return;
}
int main(void){
//    freopen("input.txt", "r", stdin);
    int tc;

    cin >> tc;
    while(tc-- > 0){
        int boardSize;
        cin >> boardSize;
        int i, j;
        int board[100][100] = {0, };
        int solve[100][100] = {0, };
        FOR(i, boardSize){
            FOR(j, boardSize){
                cin >> board[i][j];
            }
        }
        searchBoard(solve, board, boardSize);

        if(solve[boardSize-1][boardSize-1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}