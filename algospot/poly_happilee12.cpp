//
// Created by HANLEEKYEUNG on 2017. 2. 20..
//
#include<iostream>
#include <string.h>
// memset (target, char, num)
#define FOR(i, st, ed) for(int i = st ; i <= ed; i++)
using namespace std;

int sol[101][101];
int tc;
int target;
// x개 짜리 중 맨 윗줄이 y개 짜리인 것
int makesol(int x, int y){
    if(sol[x][y] == 0) {
        if(x==y){
            sol[x][y] = 1;
        }
        else {
            int temp = 0;
            FOR(j, 1, x - y) {
                // 겹치는 면의 사각형이 y, j개면 겹침은 y+j-1개가 생김
                temp = (temp + (y + j - 1) * makesol(x - y, j)) % 10000000;
            }
            sol[x][y] = temp;
        }
    }
    return sol[x][y];
}

int getsol(int x){
    int rslt = 0;
    FOR(i, 1, x){
        rslt = ( makesol(x, i) + rslt )% 10000000;
    }
    return rslt;
}

int main(void){
    memset(sol,0,101*101);
    cin >> tc;
    FOR(i, 1, tc){
        cin >> target;
        cout << getsol(target) << endl;
    }
    return 0;
}