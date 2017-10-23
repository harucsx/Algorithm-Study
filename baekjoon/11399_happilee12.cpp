//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(var, ed) for(int var = 0; var < ed; var++)
using namespace std;
int n, since = 0, total = 0;;
vector<int> wd;
int pop_front(vector<int> &a){
    int ret = a.front();
    a.erase(a.begin());
    return ret;
}
int main(){
//    freopen("input.txt", "r", stdin);
    //inputs
    cin >> n;
    wd.resize(n);
    FOR(i, n){
        cin >> wd[i];
    }
    sort(wd.begin(), wd.end());

    while(!wd.empty()){
        int front = pop_front(wd);
        total += (since+front);
        since += front;

    }
    cout << total << endl;
    return 0;
}
