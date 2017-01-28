//
// Created by HANLEEKYEUNG on 2017. 1. 26..
// 오답
//


#include <iostream>
using namespace std;

int findMax(int board[], int length){
    int max = 0;
    int prev[10001] = {0,};
    if(length == 1) return board[0];

    //set first prev for
    for(int j = 0 ; j< board[0]; j++)
        prev[j] = 1;
    int prevlen = board[0];

    //for each fence
    for(int i = 1; i< length; i++){
        int temp=0;

        //prev[j] = (그 높이에 연속되는 펜스의 수)
        for(int j = board[i]; j<prevlen; j++){
            prev[j] = 0;
        }
        for(int j = 0 ; j< board[i]; j++){
            prev[j]+=1;
            if(temp < prev[j]*(j+1)) temp = prev[j]*(j+1);
            prevlen = board[i];
        }
        if(temp > max) max = temp;
//        cout << "board ; " <<board[i] << " max : " << max << endl;
    }
    return max;
}

int main(){
//    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d ",&tc);
    for(int i=0; i<tc; i++){
        int board[20000] = {0,};
        int len;
        scanf("%d ", &len);
        for(int j=0; j<len; j++) {
            scanf("%d ", &board[j]);
        }
        int max = findMax(board, len);
        cout << max <<endl;
    }
}