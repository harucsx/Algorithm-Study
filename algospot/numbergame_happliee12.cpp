#include <iostream>
#include <limits>
#include <string.h>
#define FOR(i, ed) for(int i = 0 ; i < ed; i++)
using namespace std;
//input
int tc, n;
int board[50];
//solve
int cache[50][50];
int play(int st, int ed){
    if(st == ed) return -board[st];

    int& ret = cache[st][ed];
    if(cache[st][ed] != -1) return ret;

    ret = numeric_limits<int>::min();
    if(st+2 <= ed) ret = max(ret, play(st+2, ed));
    if(st <= ed-2) ret = max(ret, play(st, ed-2));
    if(st+1<=ed) ret = max(ret, play(st+1, ed)+board[st]);
    if(st <= ed-1) ret = max(ret, play(st, ed-1)+board[ed]);
    ret = -ret;
    return ret;
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        FOR(i, n){
            cin >> board[i];
        }
        cout << -play(0, n-1) << endl;
    }
}