//
// Created by John on 2017-03-09.
//

#include <iostream>

using namespace std;

int map[1000][1000];
int visit[1000];
int cam_count;

void dfs(int map[1000][1000], int visit[1000], int n_gal, int cur_index) {
    visit[cur_index] = 1;

    for (int i = 0; i < n_gal; ++i) {
        if(!visit[i] && map[cur_index][i])
            dfs(map, visit, n_gal, i);
    }
}

void findSol(int map[1000][1000], int visit[1000], int n_gal) {
    int max = 1001;
    for (int i = 0; i < n_gal; ++i) {
        if (!visit[i])
            dfs(map, visit, n_gal, i);
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int g, h;
        cin >> g >> h;

        int f, t;
        cin >> f >> t;
        map[f][t] = 1;
        map[t][f] = 1;
        findSol(map, visit, g);

        for (int j = 0; j < g; ++j) {
            for (int k = 0; k < g; ++k) {
                map[j][k] = 0;
            }
            visit[j] = 0;
        }
    }

}