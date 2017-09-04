//
// Created by HANLEEKYEUNG on 2017. 9. 4..
// 알고리즘 문제해결전략 정답 참고
//

#include <iostream>

using namespace std;

#define FOR(var, num) for(int var=0; var<num; var++)
#define MIN -500000

int board[50];
int cache[50][50];

int play(int left, int right){
    if(left > right) return 0;
    int& ret = cache[left][right];
    if(ret != MIN) return ret;

    ret = max(board[left]-play(left+1, right),
              board[right]-play(left, right-1));
    if(left+1<=right){
        ret = max(ret, -play(left+2, right));
        ret = max(ret, -play(left, right-2));
    }
    return ret;
}
int main(){
//    freopen("input.txt", "r", stdin);
    int tc; cin >> tc;
    while(tc--){
        // init board
        int size; cin >> size;
        FOR(i, size){
            int temp; cin >> temp;
            board[i] = temp;
        }

        //init cache
        FOR(i, 50)
            FOR(j, 50)
                cache[i][j] = MIN;

        cout << play(0, size-1) << endl;
    }
}