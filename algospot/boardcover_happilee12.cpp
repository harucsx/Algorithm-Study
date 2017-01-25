//
// Created by HANLEEKYEUNG on 2017. 1. 26..
//

//
// Created by HANLEEKYEUNG on 2017. 1. 25..
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void printBoard(int wh, int ht, int board[20][20]){
    for(int i=0; i<ht; i++){
        for(int j=0; j<wh; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int fillBorad(int wh, int ht, int board[20][20]) {
    int result = 0;
    int x = -1, y = -1;
    int a = -1, b = -1;
    bool breaker = false;
    for (int i = 0; i < ht; i++) {
        if(breaker) break;
        for (int j = 0; j < wh; j++) {
            if (board[i][j] == 1) {
                a= x = i;
                b = y = j;
                breaker = true;
                break;
            }
        }
    }

    if(x == -1 && y == -1) {
        return 1;
    }

    if( !(board[x+1][y] && board[x+1][y+1]) && !(board[x][y+1] && board[x+1][y+1]) && !(board[x][y+1] && board[x+1][y]) &&!(board[x+1][y] && board[x+1][y-1]))
        return result;

    cout << "------------------" << endl;
    cout << "(x, y) : (" << x <<", " << y <<")" <<endl;
    printBoard(wh, ht, board);


    //case1 :: ㄴ
    if(board[x+1][y] && board[x+1][y+1]) {
        cout << " => case 1 " <<endl;
        board[x][y] = board[x+1][y] = board[x+1][y+1] = 0;
        result += fillBorad(wh, ht, board);
        board[x][y] = board[x+1][y] = board[x+1][y+1] = 1;
    }
    //case2 :: ㄱ
    if(board[x][y+1] && board[x+1][y+1]) {
        cout << " => case 2 " <<endl;
        board[x][y] = board[x][y+1] = board[x+1][y+1] = 0;
        result += fillBorad(wh, ht, board);
        board[x][y] = board[x][y+1] = board[x+1][y+1] = 1;
    }
    //case3 :: |-
    if(board[x][y+1] && board[x+1][y]) {
        cout << " => case 3 " <<endl;
        board[x][y] = board[x][y+1] = board[x+1][y] = 0;
        result += fillBorad(wh, ht, board);
        board[x][y] = board[x][y+1] = board[x+1][y] = 1;
    }
    //case4 :: _|
    if(board[x+1][y] && board[x+1][y-1]) {
        cout << " => case 4 " <<endl;
        board[x][y] = board[x+1][y] = board[x+1][y-1] = 0;
        result += fillBorad(wh, ht, board);
        board[x][y] = board[x+1][y] = board[x+1][y-1] = 1;
    }

    return result;
}

int main(){
    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int i=0; i<tc; i++){
        int board[20][20];
        int wh, ht;
        int sum =0;
        string line;
        cin >> ht >> wh;
        memset(board, 0, 400);

        for(int i=0; i<ht; i++) {
            cin >> line;
            for(int j=0; j<wh; j++)
                if(line[j] == '.'){
                    board[i][j] = 1;
                    sum ++;
                }
        }
        if(sum%3 !=0){
            cout << "0" << endl;
        }
        else {
            cout << fillBorad(wh, ht, board) << endl;
        }
    }
}