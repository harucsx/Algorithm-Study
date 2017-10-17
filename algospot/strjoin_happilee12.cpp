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
void printVect(const vector<int> &a){
    for(int x : a)
        cout << x << " ";
    cout << endl;
}
int pop_front(vector<int> &a){
    int ret = a.front();
    a.erase(a.begin());
    return ret;
}
void insert_sorted(vector<int> &a, int value){
    for(int i = 0; i<a.size(); i++)
        if(a[i] > value){
            a.insert(a.begin()+i, value);
            return;
        }

}
int greedy(vector<int> &strLength){
    if(strLength.size()<=1) return 0;
    int sum = pop_front(strLength)+pop_front(strLength); // 가장 작은 값 + 두번째로 작은 값 & 배열에서 두 값 삭제
    strLength.push_back(sum); // 두 값의 합을 배열에 넣고
    sort(strLength.begin(), strLength.end()); // 배열 재정렬
    return sum+ greedy(strLength);
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<int> strLength(n);
        FOR(i, n)
            cin >> strLength[i];
        sort(strLength.begin(), strLength.end());
        cout << greedy(strLength) << endl;

    }
}
