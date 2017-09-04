//
// Created by HANLEEKYEUNG on 2017. 8. 30..
// 포기..
//
#include<iostream>
#include <vector>
#define FOR(a, num) for(int a=0; a<num; a++)
using namespace std;

//board
struct sBoard {
    int board[6][6];
    int step;
};

//변수선언
int testcase;
vector<sBoard> boardVec;

void inputBoard(){
    sBoard inputBoard;
    inputBoard.step = 0;
    char input;
    FOR(row, 5){
        FOR(col, 5){
            scanf("%c", &input);
            if(input == '.') inputBoard.board[row][col] = 1;
            else if(input == '#') inputBoard.board[row][col] = 0;
            else
                cout << "something wrong on " << row <<" " <<col <<endl;
        }
        scanf("\n");
    }
    boardVec.push_back(inputBoard);
}
void printBoard(){
    sBoard popBoard = boardVec.back();
    FOR(row, 5){
        FOR(col, 5){
            printf("%d ", popBoard.board[row][col]);
        }
        cout << endl;
    }
    cout << endl;

}

int solve(){
    sBoard popBoard = boardVec.back();
//    printBoard();
    FOR(row, 5){
        FOR(col, 5) {
            if(popBoard.board[row][col] == 1){

                // [][] case1
                if(popBoard.board[row][col+1] == 1){
                    sBoard newBoard = boardVec.back();
                    newBoard.board[row][col] = 0;
                    newBoard.board[row][col+1] = 0;
                    newBoard.step++;
                    boardVec.push_back(newBoard);
                    if(solve()%2 == 1){
                        return 1;
                    }

                    //[][] case2
                    //  []
                    if(popBoard.board[row+1][col+1] == 1){
                        sBoard newBoard = boardVec.back();
                        newBoard.board[row][col] = 0;
                        newBoard.board[row][col+1] = 0;
                        newBoard.board[row+1][col+1] = 0;
                        newBoard.step++;
                        boardVec.push_back(newBoard);
                        if(solve()%2 == 1){
                            return 1;
                        }
                    }
                }

                // [] case3
                // []
                if(popBoard.board[row+1][col] ==1){
                    sBoard newBoard = boardVec.back();
                    newBoard.board[row][col] = 0;
                    newBoard.board[row+1][col] = 0;
                    newBoard.step++;
                    boardVec.push_back(newBoard);
                    if(solve()%2 == 1){
                        return 1;
                    }
                    // [] case4
                    // [][]
                    if(popBoard.board[row+1][col+1] == 1){
                        sBoard newBoard = boardVec.back();
                        newBoard.board[row][col] = 0;
                        newBoard.board[row+1][col] = 0;
                        newBoard.board[row+1][col+1] = 0;
                        newBoard.step++;
                        boardVec.push_back(newBoard);
                        if(solve()%2 == 1){
                            return 1;
                        }
                    }
                    //   [] case5
                    // [][]
                    if(col != 0 && (popBoard.board[row+1][col-1]==1)){
                        sBoard newBoard = boardVec.back();
                        newBoard.board[row][col] = 0;
                        newBoard.board[row+1][col] = 0;
                        newBoard.board[row+1][col-1] = 0;
                        newBoard.step++;
                        boardVec.push_back(newBoard);
                        if(solve()%2 == 1){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    boardVec.pop_back();
    return popBoard.step;
}

int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d\n", &testcase);
    while(testcase--){
        inputBoard();
        cout << "-----[[" << testcase <<"]]--------" <<endl;
        printBoard();
        cout << solve() << endl << endl;
        boardVec.clear();
    }
    return 0;
}

