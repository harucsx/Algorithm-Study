//
// Created by HANLEEKYEUNG on 2017. 1. 25..
//

//
// Created by HANLEEKYEUNG on 2017. 1. 25..
//

#include <iostream>
#include <string.h>

using namespace std;

int student;
int numOfPair;
int pair[10][10];
int unused[10];
int a, b;
int total;

void makepair();
void seek(int a, int b, int *unused);
void match(int a, int b, int *unused);
void printUnused(int *unused);
int check(int* unused);

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    int test;
    cin >> test;

    //testcases
    for(int n = 0; n<test; n++) {
        total = 0;
        cin >> student >> numOfPair;

        memset(unused, 0, sizeof(unused));
        for (int i = 0; i < student; i++)
            memset(::pair[i], 0, sizeof(::pair[i]));

        //input으로 pair만들기
        makepair();

        //0에 대해 매치 찾기
        for (int i = 1; i < student; i++) {
            match(0, i, unused);
        }

        cout << total <<endl;
    }
}

void makepair(){
    //pair 배열
    for (int j = 0; j < numOfPair; j++) {
        cin >> a >> b;

        //작은걸 a에
        if (a > b) {
            int temp = b;
            b = a;
            a = temp;
        }

        ::pair[a][b] = 1;
    }
}

void seek(int a, int b, int *unused){
    //새로운 unused
    int nUsd[10];
    for(int i =0 ; i< student; i++)
        nUsd[i] = unused[i];
    nUsd[a] = 1;
    nUsd[b] = 1;

    //매칭 끝일 경우
    if(check(nUsd) == 0){
        total++;
        return;
    }

    //다음 매칭
    for(int i=a+1; i<student; i++){ //a 이전꺼는 이미 셈
        if(nUsd[i]==1) continue;
        for(int j=i+1; j<student; j++){
            if(nUsd[j]==1) continue;
            //매치 되는지 찾기
            match(i, j, nUsd);
        }
    }
}

void match(int a, int b, int *unused){
    if(unused[a] == 0 && unused[b] == 0 && ::pair[a][b] == 1){
        //매치되면 이걸로 또 찾음
        seek(a, b, unused);
    }
    else return;
}
void printUnused(int *unused){
    cout << "unused :: ";
    for(int i = 0; i<student; i++){
        cout <<unused[i] << " ";
    }
    cout << endl;
}

int check(int* unused){
    for(int i=0; i<::student; i++){
        if(unused[i] == 0)
            return 1;
    }
    return 0;
}
