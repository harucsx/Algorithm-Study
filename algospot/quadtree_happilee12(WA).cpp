//
// Created by HANLEEKYEUNG on 2017. 1. 28..
//


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void printBoard(int board[17][17]){
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int zip(int board[17][17], char ziped[256], int cha, int width, int x, int y){
    if(width == 1){
        ziped[cha] = board[x][y];
        return cha;
    }
    width = width/2;
    if( (board[x][y]&&board[x+width][y]&&board[x][y+width]&&board[x+width][y+width]) ||
        (!board[x][y]&&!board[x+width][y]&&!board[x][y+width]&&!board[x+width][y+width])){
        ziped[cha] = board[x][y];
        return cha;
    }
    else {
        ziped[cha] = 'x';
        cha = zip(board, ziped, cha + 1, width, x, y);
        cha = zip(board, ziped, cha + 1, width, x, y+width);
        cha = zip(board, ziped, cha + 1, width, x+width, y);
        cha = zip(board, ziped, cha + 1, width, x+width, y+width);
        return cha;
    }
}

int drawBoard(int board[17][17], string input, int cha, int width, int x, int y){
    if(input[cha] == 'x'){
        cha = drawBoard(board, input, cha+1, width/2, x, y);
        cha = drawBoard(board, input, cha+1, width/2, x, y+width/2);
        cha = drawBoard(board, input, cha+1, width/2, x+width/2, y);
        cha = drawBoard(board, input, cha+1, width/2, x+width/2, y+width/2);
    }
    else if (input[cha] == 'b'){ // black => 0
        for(int i = 0; i<width; i++){
            for(int j = 0; j < width; j++){
                board[x+i][y+j] = 0;
            }
        }
    }
    else if(input[cha] == 'w'){
        for(int i = 0; i<width; i++){
            for(int j = 0; j < width; j++){
                board[x+i][y+j] = 1;
            }
        }
    }
    return cha;
}

void reverseBoard(int board[17][17]){
    int line[17];
    for(int i=0; i<8; i++) {
        for (int j = 0; j < 16; j++) {
            line[j] = board[i][j];
            board[i][j] = board[15-i][j];
            board[15-i][j] = line[j];
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d ",&tc);

    for(int i=0; i<tc; i++){
        int board[17][17] = {0, };
        char ziped[1000];
        string input;
        getline(cin, input);
        drawBoard(board,input, 0, 16, 0, 0);
        reverseBoard(board);
        int length = zip(board, ziped, 0, 16, 0, 0);
        for(int j = 0 ; j<length+1; j++) {
            if(ziped[j]==0) cout << 'b';
            else if(ziped[j]==1) cout << 'w';
            else
                cout << ziped[j];
        }
        cout << endl;
    }
}