//
// Created by HANLEEKYEUNG on 2017. 1. 25..
//

#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>

using namespace std;

int printArray(int target[], int length){
    for(int i=0; i<length; i++)
        cout << target[i] << " ";
    cout << endl;
}

void initArray(int target[], int length){
    for(int i=0; i<length; i++){
        target[i] = 0;
    }
}

int sumArray(int target[], int length){
    int sum = 0;
    for(int i=0; i<length; i++) {
        sum += target[i];
    }
    return sum;
}

void plus1(int times[11], int redix){
    if(times[redix]!=3) times[redix]++;
    else{
        times[redix] = 0;
        return plus1(times, redix+1);
    }
}

bool aClock(int clock, int board[16][10], int times[11], int target[16]){
    int temp = 0;
    for(int i=0; i<10; i++){
        temp += (board[clock][i] * times[i]);
    }
    if(temp % 4 == target[clock]) return true;
    else return false;
}

bool everyClock(int board[16][10], int times[11], int target[16]){
    for(int i=0; i<16; i++) {
        if(!aClock(i, board, times, target))  return false;
        if(i==15){
//            printArray(times, 11);
            return true;
        }
    }
}

int main(){
//    freopen("input.txt", "r", stdin);
    int times[11];
    int target[16];
    int input;
    int output;
    int board[16][10] = {
            {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 0, 1, 0, 1, 1},
            {0, 0, 1, 1, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 1, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 1, 0, 0, 1, 1, 1, 0, 0}
            //8-12, 14-15
    };
    for(int i=0; i<16; i++)
        for(int j=0; j<10; j++)
            board[i][j] = board[i][j]*3;
    int tc;
    cin >> tc;

    for(int i=0; i<tc; i++){
        initArray(times, 11);
        initArray(target, 16);
        input = 0;
        output = 50;

        //init clock
        for(int j=0; j<16; j++) {
            cin >> input;
            target[j] = (input/3)%4;
        }


        while(times[10]==0){
            if(everyClock(board, times, target)) {
                if(sumArray(times, 10)<output)
                    output = sumArray(times, 10);
            }
            plus1(times, 0);
        }

        if(output == 50){
            cout << "-1" << endl;
        }
        else
            cout << output << endl;
    }
}