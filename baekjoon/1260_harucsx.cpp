#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>

using namespace std;

bool map[1001][1001];
bool visit[1001];

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, M, V;

    stack<int> s;
    queue<int> q;

    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        map[x][y] = map[y][x] = true;
    }

    s.push(V);

    while(!s.empty()){
        bool prev = true;
        int now = s.top();
        if (!visit[now]){
            visit[now] = true;
            cout << now << " ";
        }

        for (int i = 1; i <= N; ++i) {
            if (i != now && !visit[i] && map[now][i]){
                s.push(i);
                prev = false;
                break;
            }
        }

        if (prev)
            s.pop();
    }

    cout << endl;

    fill_n(visit, 1001, false);

    q.push(V);

    while(!q.empty()){
        int now = q.front();
        if (!visit[now]){
            visit[now] = true;
            cout << now << " ";
        }

        q.pop();

        for (int i = 1; i <= N ; ++i) {
            if (i != now && !visit[i] && map[now][i]){
                q.push(i);
            }
        }

    }
    return 0;
}
