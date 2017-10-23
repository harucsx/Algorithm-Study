//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(var, ed) for(int var = 0; var < ed; var++)
using namespace std;
int n;
vector<pair<int, int>> meeting;
int main(){
//    freopen("input.txt", "r", stdin);

    //inputs
    cin >> n;
    meeting.resize(n);
    FOR(i, n){
        int st, ed;
        cin >> st >> ed;
        meeting[i] = make_pair(ed, st);
    }
    //끝나는 순으로 정렬
    sort(meeting.begin(), meeting.end());

    int ret =0, current = 0;
    FOR(i, n){
        if(meeting[i].second >= current){
            ret++;
            current = meeting[i].first;
        }
    }
    cout << ret << endl;

    return 0;
}
