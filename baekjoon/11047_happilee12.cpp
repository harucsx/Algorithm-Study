//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
#define FOR(var, ed) for(int var = 0; var < ed; var++)
using namespace std;
int n, k, coins[10];
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    FOR(i, n)
        cin >> coins[i];
    int ret=0;
    FOR(i, n){
        ret += k/coins[n-i-1];
        k %= coins[n-i-1];
    }
    cout << ret << endl;
    return 0;
}