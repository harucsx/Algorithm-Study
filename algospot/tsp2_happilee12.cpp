//
// Created by HANLEEKYEUNG on 2017. 10. 13..
//

//https://algospot.com/judge/problem/read/TSP1
//https://algospot.com/judge/problem/read/TSP2

#include <iostream>
#include <cstring>
#include <limits>
#include <bitset>
#define FOR(i, ed) for(int i = 0 ; i < ed; i++)
#define INF std::numeric_limits<double>::infinity();
#define MAX 20
using namespace std;

// input
int tc, n;
double distBtwCity[MAX][MAX]; //distances between city i and j
// for algorithm
double cache[MAX][1<<MAX]; // 2^(MAX-1)인가?
void inputData(){
    FOR(i, n)
        FOR(j, n)
            cin >> distBtwCity[i][j];
}
double play2(int here, int visited){
//    cout << "here: " << here <<" visited : " << bitset<32>(visited) <<endl;
    if(visited == (1<<n)-1) return 0;
    double &ret = cache[here][visited];
    if(ret >0) return ret;
    ret = INF;
    FOR(next, n){
        if(visited & (1<<next)) continue;
        double cand = distBtwCity[here][next]+play2(next, visited+(1<<next));
        ret = min(ret, cand);
    }
    return ret;
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        inputData();
        double rslt = INF;
        FOR(start, n){
            rslt = min(rslt, play2(start, 1<<start));
        }
        cout.precision(10);
        cout << rslt << endl;
    }
}