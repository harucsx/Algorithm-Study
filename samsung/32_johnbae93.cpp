//
// Created by John on 2017-05-02.
//
#include <stdio.h>

int n;
typedef struct {
    int x;
    int y;
    int type;
}POS;

POS pos[100000];
int count;

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
            scanf("%d %d %d", &pos[i].x, &pos[i].y, &pos[i].type);
        }



        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d", count);

        for (int i = 0; i < n; ++i) {
            pos[i].x = 0;
            pos[i].y = 0;
            pos[i].type = 0;
        }

    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
