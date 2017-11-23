//
// Created by John on 2017-05-03.
//
#include <stdio.h>

int k, l;
int n, m;

int map[110][110];
int degree[110];
int sol;

int v;
void del_node(int index) {
    sol+=index;
    degree[index] = -1;
    v--;

    for (int i = 1; i <= n; ++i) {
        if(map[index][i]){
            map[index][i] = 0;
            map[i][index] = 0;
            degree[i]--;
        }
    }
}

int findSol() {
    int find;
    do{
        find = 0;
        for (int i = 1; i <= n; ++i) {
            if(degree[i] >= 0 && degree[i] < k) {
                find = 1;
                del_node(i);
            }
        }
    }while(find);

    for (int j = 1; j <= n; ++j) {
        if(degree[j] != -1 && degree[j] > v - l - 1) {
            del_node(j);
            find = 1;
        }
    }
    return find;
}

int main(void) {
    freopen("input.txt", "r", stdin);

    setbuf(stdout, NULL);

    int T;
    int test_case;
    int a, b;

    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d %d", &k, &l);
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            map[a][b] = 1;
            map[b][a] = 1;
            degree[a]++;
            degree[b]++;
        }

        v = n;
        while(findSol());


        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);

        printf("%d\n", sol);
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n ; ++i) {
                map[i][j] = 0;
            }
            degree[j] = 0;
        }
        sol = 0;
    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
