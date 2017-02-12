//
// Created by John on 2017-02-05.
//

#include <iostream>
#include <cstdio>
#include <vector>

using  namespace std;

int clock_switch[10][16] = { {3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,3,0,0,0,3,0,3,0,3,0,0,0,0},
                             {0,0,0,0,3,0,0,0,0,0,3,0,0,0,3,3},
                             {3,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,3,3,3,0,3,0,3,0,0,0},
                             {3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,3},
                             {0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,3},
                             {0,0,0,0,3,3,0,3,0,0,0,0,0,0,3,3},
                             {0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,3,3,3,0,0,0,3,0,0,0,3,0,0} };

void turn(vector<int> &v, int switch_num){

    for (int j = 0; j < 16; ++j) {
        v[j] = (v[j] + clock_switch[switch_num][j]) % 12;
    }
}

bool check(vector<int> &v) {
    for (int i = 0; i < 16; ++i) {
        if(v[i]%12 != 0)
            return false;
    }
    return true;
}

void findSol(vector<int> &v, int *sol, int count, int clock_switch) {
    if (check(v)) {
        if (*sol > count) *sol = count;
        return ;
    }
    else if(clock_switch  > 9) return ;
    for (int i = 0; i < 4; ++i) {
        findSol(v, sol, count + i, clock_switch + 1);
        turn(v, clock_switch);
    }
    return ;
}


int main(){
    int T;
    int test_case;

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++) {
        vector<int> v;

        int tmp;
        int front = -1;
        int rear = -1;
        for (int i = 0; i < 16; ++i) {
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
        int sol = 999;
        findSol(v, &sol, 0, 0);
        if (sol == 999) sol = -1;
        printf("%d\n", sol);
    }
}