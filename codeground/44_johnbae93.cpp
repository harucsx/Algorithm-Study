//
// Created by John on 2017-03-10.
// [Complete!]
//

#include <cstdio>
#include <iostream>

using namespace std;

int map[1000][1000];
bool visit[1000];
int check[1000];

int dfs(int num, int cur_index, int checking) {
    visit[cur_index] = true;
    check[cur_index] = checking;
    for (int i = 0; i < num; ++i) {
        if (map[cur_index][i]) {

            if (check[i] == checking)
                return -1;

            if (!visit[i]) {
                int next_checking;
                if (checking == 1)
                    next_checking = 2;
                else
                    next_checking = 1;

                if (dfs(num, i, next_checking) == -1)
                    return -1;

            }
        }
    }
    return 1;
}

int findSol(int num) {
    for (int i = 0; i < num; ++i) {
        if (!visit[i]) {
            if (dfs(num, i, 1) == -1)
                return -1;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);    // Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for (test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        int num;
        scanf("%d", &num);
        int adj;
        scanf("%d", &adj);

        int a, b;

        for (int i = 0; i < adj; ++i) {
            scanf("%d %d", &a, &b);
            map[a - 1][b - 1] = 1;
            map[b - 1][a - 1] = 1;
        }

        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);

        if (findSol(num) == -1)
            printf("0\n");
        else
            printf("1\n");

        for (int j = 0; j < num; ++j) {
            for (int i = 0; i < num; ++i) {
                map[i][j] = 0;
            }
            visit[j] = false;
            check[j] = 0;
        }

    }

    return 0;    // 정상종료 시 반드시 0을 리턴해야 합니다.
}
/*
2
5
4
1 2
2 3
2 4
4 5
5
5
1 2
2 3
2 4
2 5
4 5
 */