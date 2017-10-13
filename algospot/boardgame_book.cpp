//
// Created by HANLEEKYEUNG on 2017. 9. 9..
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//define
#define CACHEMAX 33554433
#define FOR(var, num) for(int var=0; var<num; var++)

vector <int> moves;
inline int cell(int y, int x){return 1<< (y*5+x);}
//블록들의 위치를 미리 계산
void precalc(){
    //3칸짜리 블록들
    for(int y = 0; y<4; y++)
        for(int x = 0; x<4; x++){
            vector<int> cells;
            for(int dy = 0 ; dy<2; dy++)
                for(int dx = 0; dx < 2; dx++)
                    cells.push_back(cell(y+dy, x+dx));
            int square = cells[0]+cells[1]+cells[2]+cells[3];
            for(int i = 0; i < 4; i++)
                moves.push_back(square-cells[i]);
        }
    //두칸짜리 블록
    for(int i = 0 ; i < 5; i++)
        for(int j = 0 ; j < 4; j++){
            moves.push_back(cell(i, j) + cell(i, j+1));
            moves.push_back(cell(j, i) + cell(j+1, i));
        }
}

char cache[1<<25];
//현재 게임판 상태가 board일 때 현재 차례인 사람이 승리할지 여부를 반환
//(y,x)칸에 블록이 있다 <=> (y*5+x)번 비트가 켜져 있다
char play(int board){
    char& ret = cache[board];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i<moves.size(); i++)
        if((moves[i] & board) == 0)
            if(!play(board | moves[i])){
                ret = 1;
                break;
            }
    return ret;
}
//init
vector<string> board;
//int cache[CACHEMAX];
//void initcache(){
//    FOR(i, CACHEMAX)
//        cache[i] = -2;
//}
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
int main(){
    int t; cin>>t;
    precalc();
    while(t--){
        memset(cache, -1, sizeof(cache));
        int board=0;
        for(int y=0; y<5; ++y)
            for(int x=0; x<5; ++x){
                char c; cin>>c;
                if(c=='#') board+=cell(y,x);
            }
        if(play(board)) cout<<"WINNING"<<endl;
        else cout<<"LOSING"<<endl;
    }

    return 0;
}

