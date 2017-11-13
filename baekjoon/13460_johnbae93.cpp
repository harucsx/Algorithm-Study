//
// Created by John on 2017-03-12.
//[아직....]
#include <cstdio>
#include <iostream>

using namespace std;

int map[10][10]; // wall : 1

//int R_loc[2];
//int B_loc[2];
int O_loc[2];

int checkExit(int x, int y) {
    if(x == O_loc[0] && y == O_loc[1])
        return 1;
    else
        return 0;
}

int moveToEnd(int x, int y, int cur_x, int cur_y){
    if(x == -1){
        while(map[cur_x - 1][cur_y] != 1) {
            cur_x--;
            if(checkExit(cur_x, cur_y))
                return 0;
        }
        return cur_x;
    }
    if(x == 1){
        while(map[cur_x + 1][cur_y] != 1) {
            cur_x++;
            if(checkExit(cur_x, cur_y))
                return 0;
        }
        return cur_x;
    }
    if(y == -1){
        while(map[cur_x][cur_y - 1] != 1) {
            cur_y--;
            if(checkExit(cur_x, cur_y))
                return 0;
        }
        return cur_y;
    }
    if(y == 1){
        while(map[cur_x][cur_y + 1] != 1) {
            cur_y++;
            if(checkExit(cur_x, cur_y))
                return 0;
        }
        return cur_y;
    }

}
int findSol(int n, int m, int R_loc[2], int B_loc[2], int count) {
    int first_R[2];
    int first_B[2];

    // 처음 공들의 위치 저장
    first_R[0] = R_loc[0];
    first_R[1] = R_loc[1];

    first_B[0] = B_loc[0];
    first_B[1] = B_loc[1];

    if(count > 10)
        return -1;

    int ret;

    int R_ret;
    int B_ret;
    // -x direction   // 배열형태로 보내기
    R_loc[0] = moveToEnd(-1, 0, R_loc[0], R_loc[1]);
    B_loc[0] = moveToEnd(-1, 0, B_loc[0], B_loc[1]);

    if(B_loc[0] == 0)
        return -1;
    if(R_loc[0] == 0)
        return count + 1;

    ret = findSol(n, m, R_loc, B_loc, count + 1);
    R_loc[0] = first_R[0];
    R_loc[1] = first_R[1];

    B_loc[0] = first_B[0];
    B_loc[1] = first_B[1];
    if(ret != -1) return ret;


    // +x direction
    R_loc[0] = moveToEnd(1, 0, R_loc[0], R_loc[1]);
    B_loc[0] = moveToEnd(1, 0, B_loc[0], B_loc[1]);

    if(B_loc[0] == 0)
        return -1;
    if(R_loc[0] == 0)
        return count + 1;

    ret = findSol(n, m, R_loc, B_loc, count + 1);
    R_loc[0] = first_R[0];
    R_loc[1] = first_R[1];

    B_loc[0] = first_B[0];
    B_loc[1] = first_B[1];
    if(ret != -1) return ret;


    //-y direction
    R_loc[1] = moveToEnd(0, -1, R_loc[0], R_loc[1]);
    B_loc[1] = moveToEnd(0, -1, B_loc[0], B_loc[1]);

    if(B_loc[1] == 0)
        return -1;
    if(R_loc[1] == 0)
        return count + 1;

    ret = findSol(n, m, R_loc, B_loc, count + 1);
    R_loc[0] = first_R[0];
    R_loc[1] = first_R[1];

    B_loc[0] = first_B[0];
    B_loc[1] = first_B[1];
    if(ret != -1) return ret;


    // +y direction
    R_loc[1] = moveToEnd(0, 1, R_loc[0], R_loc[1]);
    B_loc[1] = moveToEnd(0, 1, B_loc[0], B_loc[1]);

    if(B_loc[1] == 0)
        return -1;
    if(R_loc[1] == 0)
        return count + 1;

    ret = findSol(n, m, R_loc, B_loc, count + 1);
    R_loc[0] = first_R[0];
    R_loc[1] = first_R[1];

    B_loc[0] = first_B[0];
    B_loc[1] = first_B[1];
    if(ret != -1) return ret;

    return -1;

}

int main(){
    int n, m;
    //scanf("%d %d", &n, &m);
    cin>>n>>m;
    char tmp;
    int R_loc[2];
    int B_loc[2];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //scanf("%c", &tmp);
            //if(tmp == '\n')
              //  scanf("%c", &tmp);
            cin>>tmp;
            if(tmp == '#')
                map[i][j] = 1;
            if(tmp == 'B') {
                B_loc[0] = i;
                B_loc[1] = j;
            }
            if(tmp == 'R') {
                R_loc[0] = i;
                R_loc[1] = j;
            }
            if(tmp == 'O') {
                O_loc[0] = i;
                O_loc[1] = j;
            }
        }
    }
    int sol = findSol(n, m, R_loc, B_loc, 0);
    cout<<sol<<endl;

}

