//
// Created by John on 2017-03-12.
//[Complete! 교훈 : 정답 변수 범위 확인하기!!]
#include <iostream>
#include <cstdio>

int people[100010];
long long count_main;
long long count_sub;

using namespace std;

int upper(int numerator, int denominator){
    if(numerator%denominator == 0)
        return numerator/denominator;
    else
        return numerator/denominator + 1;
}

int findSol(int num_room, int main, int sub) {
    for (int i = 0; i < num_room; ++i) {
        if (main >= people[i]) {
            count_main++;

        } else {
            people[i]-=main;
            count_main++;
            count_sub = count_sub + upper(people[i], sub);
        }
    }
}


int main() {
    int room;
    scanf("%d", &room);
    for (int i = 0; i < room; ++i) {
        scanf("%d", &people[i]);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    findSol(room, a, b);
    cout<<count_main + count_sub<<endl;
}
