//
// Created by HANLEEKYEUNG on 2017. 2. 20..
//

#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(st, ed) for(int i = st ; i < ed; i++)
#define MAX    1000000007

using namespace std;

// 변수선언
int tc, max_tile = 0;
vector<int> tiles;
int cache[101] = {0, };
// 벡터 출력 함수
void print(vector<int> &a) {
    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}
// 벡터 정렬용
bool comp(int a, int b) {
    return (a < b);
}

//** function **
int sum1007(int num1, int num2){
    if(num1 + num2 > 1000000007)
        return num1-1000000007+num2;
    else return num1+num2;
}
int main(void){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    FOR(0, tc){
        int tile;
        cin >> tile;
        if(tile>max_tile) max_tile = tile;
        tiles.push_back(tile);
    }

    //피보나치 적용
    cache[1] = 1;
    cache[2] = 2;
    FOR(3, max_tile+1){
        cache[i] = sum1007(cache[i-1], cache[i-2]);
//        cout << i <<": " << cache[i] << "\n";
    }


    FOR(0, tc){
        cout << cache[tiles[i]] << '\n';
    }


    return 0;
}
