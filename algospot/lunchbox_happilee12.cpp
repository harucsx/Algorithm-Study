//
// Created by HANLEEKYEUNG on 2017. 10. 17..
//

#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(var, ed) for(int var = 0; var<ed; var++)
using namespace std;

//input
int tc, n;
bool compare(const pair<int, int>&i, const pair<int, int>&j) { return i.second < j.second; }
int greedy(const vector<pair<int,int>> &a, int heatEnds){
    // 총 데우는 시간 + 0번쨰 도시락 먹는시간이 예상 답변
    int ret = heatEnds + a[0].second;
    //index에는 i번째 이전의 도시락까지 데우는 시간이 저장되어 있음
    int index = heatEnds - a[0].first;
    for(int i = 1; i < n ; i++){
        // 만약에 i번째도시락을 데운 후 먹는 시간이 지금 예상답변보다 길어진다면
        // i번째 도시락을 데운 후 먹는 시간이 새로운 답변이 됨
        ret = max(ret, index+a[i].second);
        // i번째 도시락 데우는 시간을 뺌
        index -= a[i].first;
    }
    return ret;
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        cin >> n;
        //pair<int, int> n개짜리 벡터를 선언
        vector<pair<int, int>> food(n);
        //도시락 정보를 입력받으면서 총 도시락 데우는 시간을 계산 -> ret에 저장
        int ret = 0;
        FOR(i, n) {
            cin >> food[i].first;
            ret += food[i].first;
        }
        FOR(i, n)
            cin >> food[i].second;
        // 도시락 먹는 시간을 기준으로 도시락 정보를 정렬
        sort(food.begin(),food.end(),compare);
        cout << greedy(food, ret) << endl;

    }
}
