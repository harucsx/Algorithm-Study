//
// Created by HANLEEKYEUNG on 2017. 11. 17..
//

#include <iostream>
#include <algorithm>
#define  FOR(var, n) for(int var  = 0 ; var < n; var++)
using namespace std;

int size, a=0, b=0, c=0;
int board[2187][2187];
bool check(int i, int j, int s){
    FOR(iindex, s)
        FOR(jindex, s)
            if(board[i+iindex][j+jindex]!= board[i][j])
                return false;
    if(board[i][j] == -1) a++;
    else if(board[i][j] == 0) b++;
    else if(board[i][j] == 1) c++;
    return true;
}
void bs(int i, int j, int s){
    FOR(iindex, 3)
        FOR(jindex, 3)
            if(!check(i+iindex*s/3, j+jindex*s/3, s/3)) bs(i+iindex*s/3, j+jindex*s/3, s/3);
}
int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d ", &size);
    FOR(i, size)
        FOR(j, size)
            scanf("%d ",&board[i][j]);
    bs(0, 0, size);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}