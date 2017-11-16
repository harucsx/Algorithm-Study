//
// Created by John on 2017-05-07.
//
#include <stdio.h>

int n;
int m[10010];
int e[10010];

int e_max_index;
int sol;
int time;

int allvisited() {
    for (int i = 0; i < n; ++i) {
        if(m[i] != -1)
            return 0;
    }
    return 1;
}
int microwave(int index) {
    return m[index];
}

void find_emax() {
    e_max_index = -1;
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if(e[i] > max && m[i] >= 0) {
            max = e[i];
            e_max_index = i;
        }
    }
}

void findSol() {
    find_emax();
    time += microwave(e_max_index);
    m[e_max_index] = -1;
    int eat_time = e[e_max_index];
    if(sol < time+eat_time)
        sol = time+eat_time;
}

int main(void) {
    freopen("input.txt", "r", stdin);

    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&m[i]);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d",&e[i]);
        }
        while(!allvisited())
            findSol();
        printf("Case #%d\n", test_case);
        printf("%d\n", sol);
        sol = 0; time = 0;
        for (int j = 0; j < n; ++j) {
            e[j] = 0;
            m[j] = 0;
        }

    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
