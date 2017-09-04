//
// Created by HANLEEKYEUNG on 2017. 9. 3..
//

#include <iostream>
#include <vector>
#define MAX 19683
#define FOR(var, num) for(int var = 0 ; var < num; var++)

using namespace std;
int cache[MAX];
vector<string> board;

bool printBoard(){
    FOR(line, 3)
        cout << board[line] << endl;
}

// turn이 이미 한줄을 만들었는지 확인. 만들었다면 true 반환
bool isFinished( char turn){
    //가로 줄 확인
    FOR(line, 3){
        FOR(col, 3){
            if(board[line][col] != turn) break;
            if(col == 2) return true;
        }
    }
    // 세로 줄 확인
    FOR(col, 3){
        FOR(row, 3){
            if(board[row][col] != turn) break;
            if(row == 2) return true;
        }
    }
    // 대각선 왼쪽아래
    FOR(line, 3){
        if(board[line][line] != turn) break;
        if(line == 2) return true;
    }
    // 대각선 오른쪽 아래
    FOR(line, 3){
        if(board[line][2-line] != turn) break;
        if(line == 2) return true;
    }
    return false;
}
//3*3 보드판을 9자리 3진수로 변환
int bijection(){
    int ret = 0;
    FOR(row, 3){
        FOR(col, 3){
            ret *= 3;
            if(board[row][col] == 'x') ret++;
            else if (board[row][col] =='o') ret+=2;
        }
    }
    return ret;
}
int tictactoe(char thisTurn){
    //저번 턴에 상대가 벌써 한 줄을 만들었다면 게임은 내가 지는 것으로 마무리 됨
    if(isFinished('x'+'o'-thisTurn)){
        return -1; // thisTurn 이 진다
    }

    int& cacheRef = cache[bijection()];
    if(cacheRef != -2) return cacheRef;
    //빈 자리에 말을 두면서 동적 프로그래밍으로 이번 턴에서 최대의 결과를 찾음.
    int minVal = 2;
    FOR(row, 3){
        FOR(col, 3){
            if(board[row][col]=='.'){
                if(minVal == -1) break;
                board[row][col] = thisTurn;
                minVal = min(minVal,tictactoe('x'+'o'-thisTurn));
                board[row][col] = '.';
            }
        }
    }
    if(minVal == 2) return cacheRef = 0;
    return cacheRef = -minVal;

}
int main(){
//    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    FOR(i, MAX){
        cache[i] = -2;
    }
    while(tc --){
        board.clear();
        int init_count = 0;
        char init_char = 'x';

        //input
        FOR(line, 3){
            string input;
            cin >> input;
            FOR(cha, 3)
                if(input[cha]!='.') init_count ++;
            board.push_back(input);
        }
        if(init_count%2 == 1) init_char = 'o';

        int result = tictactoe(init_char);

        if(result == 1) cout << init_char << endl;
        else if(result == -1){
            char opp = 'x'+'o'-init_char;
            cout << opp << endl;
        }
        else cout <<"TIE" <<endl;
//        cout << result << endl;
//        cout << tictactoe(board,init_char) << endl;
    }
}