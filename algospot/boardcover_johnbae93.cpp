#include <cstdio>
#include <iostream>

using namespace std;

int lx[4][2] = { { 1,1 },{ 0,1 },{ 0,+1 },{ 1,+1 } }; // ㄴ , _ㅣ , ㄱ, ㅣ-
int ly[4][2] = { { 0,+1 },{ 1,1 },{ 1,0 },{ 0,-1 } };

int findSol(int map[20][20], int h, int w) {
    int sol = 0;

    int x = -1, y = -1;
    bool find = false;
    for (int i = 0; i < h; ++i) {
        if (find) break;
        for (int j = 0; j < w; ++j) {
            if(map[i][j] == 1) {
                x = i;
                y = j;
                find = true;
                break;
            }
        }
    }
    if(x == -1 && y == -1) return 1;

    int count = 0;
    for (int k = 0; k < 4; ++k) {
        if(map[x+lx[k][0]][y+ly[k][0]] == 1 && map[x+lx[k][1]][y+ly[k][1]] == 1) {
            count ++;
            map[x][y] = 0;
            map[x + lx[k][0]][y + ly[k][0]] = 0;
            map[x + lx[k][1]][y + ly[k][1]] = 0;

            sol += findSol(map, h, w);

            map[x][y] = 1;
            map[x + lx[k][0]][y + ly[k][0]] = 1;
            map[x + lx[k][1]][y + ly[k][1]] = 1;
        }
    }

    return sol;
}

int main(int argc, char **argv) {
    //freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++) {
        int h, w;
        scanf("%d %d", &h, &w);
        int map[20][20] = { };
        char tmp;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                scanf(" %c", &tmp);
                map[i][j] = (tmp == '.'); // . : 1 , # : 0
            }
        }

        int sol = findSol(map, h, w);
        printf("%d\n", sol);
    }

    return 0; 
}
