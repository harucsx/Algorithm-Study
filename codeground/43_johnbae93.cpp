//
// Created by John on 2017-03-10.
//[보류]
#include <cstdio>
#include <iostream>

using namespace std;

int map[10000][10000][2];

int main(int argc, char **argv) {

    setbuf(stdout, NULL);

    int T;
    int test_case;

    int n, m;
    int a, b, p, q;

    scanf("%d", &T);    // Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for (test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d %d", &a, &b, &p, &q);
            map[a - 1][b - 1][0] = p; //android
            map[a - 1][b - 1][1] = q; //iphone
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                map[j][i][0] = 0;
                map[j][i][1] = 0;
            }
        }


        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("#testcase%d\n", test_case);

    }

    return 0;    // 정상종료 시 반드시 0을 리턴해야 합니다.
}
