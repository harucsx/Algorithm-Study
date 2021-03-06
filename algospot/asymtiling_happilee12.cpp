//
// Created by HANLEEKYEUNG on 2017. 2. 20..
//

#include<iostream>
using namespace std;

//variable declaration
int tc;
int wd;
int solution[101];

int main(void){
    cin >> tc;
    //미리 다 저장
    for(int i = 0 ; i < 101; i ++){
        int rslt;
        if(i == 0 ) rslt = 0;
        else if (i == 1) rslt = 1;
        else if (i == 2) rslt = 2;
        else rslt = (solution[i-1] + solution[i-2]) % 1000000007;
        solution[i] = rslt;
    }
    // 구하라는 숫자 구하기
    for(int i = 0 ; i < tc; i ++){
        cin >> wd;
        int a = solution[wd];
        if(wd == 1 || wd == 2 || wd == 0) a = 0;
        else{
            //짝수일 떄 대칭 : 1. 중간이 = 인 경우 2. 중간이 | 인 경우
            if(wd%2==0)
                a = (a - solution[(wd - 1) / 2] + 1000000007) % 1000000007;

            //홀수일 떄 대칭 : 중간이 | 인 경우
            a = (a - solution[wd / 2] + 1000000007) % 1000000007;

        }
        cout << a << endl;
    }
    return 0;
}
