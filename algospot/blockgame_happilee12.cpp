//// 답은 나오는데 TIME&MEMORY EXCEED
//
//#include <iostream>
//#include <vector>
//using namespace std;
////define
//#define CACHEMAX 33554433
//#define FOR(var, num) for(int var=0; var<num; var++)
////init
//vector<string> board;
//int cache[CACHEMAX];
//void initcache(){
//    FOR(i, CACHEMAX)
//        cache[i] = -2;
//}
//void inputBoard(){
//    string temp;
//    FOR(row, 5){
//        cin >> temp;
//        board.push_back(temp);
//    }
//}
//void printBoard(){
//    FOR(row, 5)
//        cout << board[row] << endl;
//}
//int bijection(){
//    int ret = 0;
//    FOR(row, 5){
//        FOR(col, 5){
//            ret *= 2;
//            if(board[row][col] == '#') ret++;
//        }
//    }
//    return ret;
//}
//int play(){
//    int& ret = cache[bijection()];
//
//    //in the cache
//    if(cache[bijection()]!=-2) return ret;
//
//    bool isFull = true;
//    FOR(row, 5){
//        FOR(col, 5){
//            if(board[row][col] == '.'){
//                board[row][col] = '#';
//                //ㄱ
//                if(col < 4 && row < 4 && board[row][col+1] == '.' && board[row+1][col+1] == '.'){
//                    board[row][col+1] = '#';
//                    board[row+1][col+1] = '#';
//                    ret = max(ret, -play());
//                    board[row][col+1] = '.';
//                    board[row+1][col+1] = '.';
//                    if(ret == 1){
//                        board[row][col] = '.';
//                        return 1;
//                    }
//                }
//                //ㄱ 좌우대칭
//                if(col < 4 && row < 4 && board[row][col+1] == '.' && board[row+1][col] == '.'){
//                    board[row][col+1] = '#';
//                    board[row+1][col] = '#';
//                    ret = max(ret, -play());
//                    board[row][col+1] = '.';
//                    board[row+1][col] = '.';
//                    if(ret == 1){
//                        board[row][col] = '.';
//                        return 1;
//                    }
//                }
//                // -
//                if(col < 4 && board[row][col+1] == '.'){
//                    board[row][col+1] = '#';
//                    ret = max(ret, -play());
//                    board[row][col+1] = '.';
//                    if(ret == 1){
//                        board[row][col] = '.';
//                        return 1;
//                    }
//                }
//                // ㄴ
//                if(col < 4 && row < 4 && board[row+1][col] == '.' && board[row+1][col+1] == '.'){
//                    board[row+1][col+1] = '#';
//                    board[row+1][col] = '#';
//                    ret = max(ret, -play());
//                    board[row+1][col+1] = '.';
//                    board[row+1][col] = '.';
//                    if(ret == 1){
//                        board[row][col] = '.';
//                        return 1;
//                    }
//                }
//                // ㄴ좌우대칭
//                if(col > 0 && row < 4 && board[row+1][col] == '.' && board[row+1][col-1] == '.'){
//                    board[row+1][col-1] = '#';
//                    board[row+1][col] = '#';
//                    ret = max(ret, -play());
//                    board[row+1][col-1] = '.';
//                    board[row+1][col] = '.';
//                    if(ret == 1){
//                        board[row][col] = '.';
//                        return 1;
//                    }
//                }
//                // |
//                if(row < 4 && board[row+1][col] == '.'){
//                    board[row+1][col] = '#';
//                    ret = max(ret, -play());
//                    board[row+1][col] = '.';
//                    if(ret == 1){
//                        board[row][col] = '.';
//                        return 1;
//                    }
//                }
//
//                board[row][col] = '.';
//            }
//        }
//    }
//
//    if(ret == -2) return ret = -1;
//    else return ret;
//}
//int main(){
//    freopen("input.txt", "r", stdin);
//    int tc; cin >> tc;
//    initcache(); // init cache with 2;
//    while(tc--) {
//        board.clear();
//        inputBoard();
//        int ret = play();
//        if(ret == 1)
//            cout << "WINNING" << endl;
//        else if(ret == -1)
//            cout << "LOSING" << endl;
//
//
//    }
//}

//#include <iostream>
//#include <limits>
//#include <string.h>
//#include <typeinfo>
//#define FOR(i, ed) for(int i = 0 ; i < ed; i++)
//using namespace std;
////input
//int tc;
////solve
//const int downCorner = (1<<21)+(1<<22)+(1<<23)+(1<<24)+(1<<20);
//const int leftCorner = (1<<0)+(1<<5)+(1<<10)+(1<<15)+(1<<20);
//const int rightCorner = (1<<4)+(1<<9)+(1<<14)+(1<<19)+(1<<24);
//
//char cache[1<<25];
//char tyle(int i, int j, int type){
//    char ret = 0;
//    ret += 1<<(i*5+j);
//    switch(type){
//        case 1: //ㄱ
//            ret += 1<<((i+1)*5+(j+1));
//            ret += 1<<(i*5+(j+1));
//            return ret;
//        case 2: // ㄴ
//            ret += 1<<((i+1)*5+(j+1));
//            ret += 1<<((i+1)*5+j);
//            return ret;
//        case 3: // ㄱ거꾸로
//            ret += 1<<((i+1)*5+j);
//            ret += 1<<(i*5+j+1);
//            return ret;
//        case 4: // ㄴ거꾸로
//            ret += 1<<((i+1)*5+(j-1));
//            ret += 1<<((i+1)*5+j);
//            return ret;
//        case 5: // -
//            ret += 1<<(i*5+j+1);
//            return ret;
//        case 6: // |
//            ret += 1<<((i+1)*5+j);
//            return ret;
//    }
//}
//char max(char a, char b){
//    if(a>=b) return a;
//    else return b;
//}
//char play(int state){
////    cout << state << endl;
//    if(state == (1<<25)-1) return -1; //lose
//    char &ret = cache[state];
//    if(ret != 0) return ret;
//
//    ret = -1;
//    FOR(i, 5){
//        FOR(j, 5){
//            if(state & 1<<(i*5+j)) continue;
//            int current = 1<<(i*5+j);
//            if(!(current&downCorner)){
//                if(!(current&leftCorner)) {
//                    if (!(state & tyle(i, j, 4))) {
//                        ret = max(ret, -play(state + tyle(i, j, 4)));
//                        if(ret == 1) return ret;
//                    }
//                }
//                if(!(current&rightCorner)) {
//                    if (!(state & tyle(i, j, 1))){
//                        ret = max(ret, -play(state + tyle(i, j, 1)));
//                        if(ret == 1) return ret;
//                    }
//                    if (!(state & tyle(i, j, 2))){
//                        ret = max(ret, -play(state + tyle(i, j, 2)));
//                        if(ret == 1) return ret;
//                    }
//                    if (!(state & tyle(i, j, 3))){
//                        ret = max(ret, -play(state + tyle(i, j, 3)));
//                        if(ret == 1) return ret;
//                    }
//                }
//                if (!(state & tyle(i, j, 6))){
//                    ret = max(ret, -play(state + tyle(i, j, 6)));
//                    if(ret == 1) return ret;
//                }
//            }
//            if(!(current&rightCorner)){
//                if (!(state & tyle(i, j, 5))){
//                    ret = max(ret, -play(state + tyle(i, j, 5)));
//                    if(ret == 1) return ret;
//                }
//            }
//        }
//    }
//    return ret;
//}
//int main(){
//
//    freopen("input.txt", "r", stdin);
//    cin >> tc;
//    while(tc--){
//        string initBoard[5];
//        memset(cache, 0, sizeof(cache));
//        FOR(i, 5){
//            cin >> initBoard[i];
//        }
//        int initState = 0;
//        FOR(i, 5){
//            FOR(j, 5){
//                if(initBoard[i][j] == '#')
//                    initState += 1<<(i*5+j);
//            }
//        }
//        play(initState);
//        if(cache[initState] == 1) cout << "WINNING" << endl;
//        else if(cache[initState] == -1) cout << "LOSING" << endl;
//    }
//}

#include <iostream>
#include <vector>
#define FOR(i, ed) for(int i = 0 ; i < ed; i++)
using namespace std;
int tc;
char cache[1<<25];
inline int cell(int y, int x){return 1<<(y*5+x);}
void preclac(vector<int> moves){
    FOR(y, 4){
        FOR(x, 4){
            vector<int> cells;
            FOR(dy, 2){
                FOR(dx, 2){
                    cells.push_back(cell(y+dy, x+dx));
                }
            }
            int square = cells[0]+cells[1]+cells[2]+cells[3];
            FOR(i, 4)
                moves.push_back(square-cells[i]);

        }
    }
    FOR(i, 5){
        FOR(j, 4){
            moves.push_back(cell(i,j)+cell(i,j+1));
            moves.push_back(cell(j,i)+cell(j+1,i));
        }
    }
}
char play(int board){
    char& ret = cache[board];
    if(ret!=-1) return ret;
    ret = 0;
    vector<int> moves;
    preclac(moves);
    FOR(i, moves.size()){
        if((moves[i]&board)==0)
            if(!play(board|moves[i])){
                ret = 1;
                break;
            }
    }
    return ret;
}
int main(){

    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        string initBoard[5];
        memset(cache, 0, sizeof(cache));
        FOR(i, 5){
            cin >> initBoard[i];
        }
        int initState = 0;
        FOR(i, 5){
            FOR(j, 5){
                if(initBoard[i][j] == '#')
                    initState += 1<<(i*5+j);
            }
        }
        if(play(initState)==1) cout << "WINNING" << endl;
        else cout << "LOSING" << endl;
    }
}