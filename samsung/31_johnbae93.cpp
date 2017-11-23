//
// Created by John on 2017-05-01.
//
#include <stdio.h>

int n;
int p[10000];
int q[10000];

int mem[10000];

int sol;

int max(int a, int b) {
    if (a>b)
        return a;
    return b;
}

void dp() {
    mem[0] = max(p[0], q[0]);
    mem[1] = max(p[0] + p[1], q[1]);
    mem[1] = max(mem[1], q[0]+p[1]);
    for (int i = 2; i < n; ++i) {
        mem[i] = max(mem[i-2] + q[i], mem[i-1]+p[i]);
    }
}
int main(void) {

    freopen("input.txt", "r", stdin);

    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &q[i]);
        }

        dp();


        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d\n", mem[n-1]);

        for (int j = 0; j < n; ++j) {
            p[j] = 0;
            q[j] = 0;
            mem[j] = 0;
        }


    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
