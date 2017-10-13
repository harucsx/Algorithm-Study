// 답은 나오는데 TIME&MEMORY EXCEED

#include <iostream>
#include <vector>
using namespace std;
//define
#define CACHEMAX 33554433
#define FOR(var, num) for(int var=0; var<num; var++)
//init
vector<string> board;
int cache[CACHEMAX];
void initcache(){
    FOR(i, CACHEMAX)
        cache[i] = -2;
}
void inputBoard(){
    string temp;
    FOR(row, 5){
        cin >> temp;
        board.push_back(temp);
    }
}
void printBoard(){
    FOR(row, 5)
        cout << board[row] << endl;
}
int bijection(){
    int ret = 0;
    FOR(row, 5){
        FOR(col, 5){
            ret *= 2;
            if(board[row][col] == '#') ret++;
        }
    }
    return ret;
}
int play(){
    int& ret = cache[bijection()];

    //in the cache
    if(cache[bijection()]!=-2) return ret;

    bool isFull = true;
    FOR(row, 5){
        FOR(col, 5){
            if(board[row][col] == '.'){
                board[row][col] = '#';
                //ㄱ
                if(col < 4 && row < 4 && board[row][col+1] == '.' && board[row+1][col+1] == '.'){
                    board[row][col+1] = '#';
                    board[row+1][col+1] = '#';
                    ret = max(ret, -play());
                    board[row][col+1] = '.';
                    board[row+1][col+1] = '.';
                    if(ret == 1){
                        board[row][col] = '.';
                        return 1;
                    }
                }
                //ㄱ 좌우대칭
                if(col < 4 && row < 4 && board[row][col+1] == '.' && board[row+1][col] == '.'){
                    board[row][col+1] = '#';
                    board[row+1][col] = '#';
                    ret = max(ret, -play());
                    board[row][col+1] = '.';
                    board[row+1][col] = '.';
                    if(ret == 1){
                        board[row][col] = '.';
                        return 1;
                    }
                }
                // -
                if(col < 4 && board[row][col+1] == '.'){
                    board[row][col+1] = '#';
                    ret = max(ret, -play());
                    board[row][col+1] = '.';
                    if(ret == 1){
                        board[row][col] = '.';
                        return 1;
                    }
                }
                // ㄴ
                if(col < 4 && row < 4 && board[row+1][col] == '.' && board[row+1][col+1] == '.'){
                    board[row+1][col+1] = '#';
                    board[row+1][col] = '#';
                    ret = max(ret, -play());
                    board[row+1][col+1] = '.';
                    board[row+1][col] = '.';
                    if(ret == 1){
                        board[row][col] = '.';
                        return 1;
                    }
                }
                // ㄴ좌우대칭
                if(col > 0 && row < 4 && board[row+1][col] == '.' && board[row+1][col-1] == '.'){
                    board[row+1][col-1] = '#';
                    board[row+1][col] = '#';
                    ret = max(ret, -play());
                    board[row+1][col-1] = '.';
                    board[row+1][col] = '.';
                    if(ret == 1){
                        board[row][col] = '.';
                        return 1;
                    }
                }
                // |
                if(row < 4 && board[row+1][col] == '.'){
                    board[row+1][col] = '#';
                    ret = max(ret, -play());
                    board[row+1][col] = '.';
                    if(ret == 1){
                        board[row][col] = '.';
                        return 1;
                    }
                }

                board[row][col] = '.';
            }
        }
    }

    if(ret == -2) return ret = -1;
    else return ret;
}
int main(){
    freopen("input.txt", "r", stdin);
    int tc; cin >> tc;
    initcache(); // init cache with 2;
    while(tc--) {
        board.clear();
        inputBoard();
        int ret = play();
        if(ret == 1)
            cout << "WINNING" << endl;
        else if(ret == -1)
            cout << "LOSING" << endl;


    }
}