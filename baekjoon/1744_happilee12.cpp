//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

// *****0 이나 1 값이 중복되어 들어오는 경우!!!!!!!!! 예외상황들 파일 만들
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, ed) for(int i = 0; i<ed; i++)
using namespace std;

int n;
vector<int> numSet;
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> n;
    int numMinus = 0, numPlus = 0, total, one =0, zero =0, temp;
    FOR(i, n){
        cin >> temp;
        if(temp == 0) zero ++;
        else if(temp == 1) one ++;
        else if(temp < 0){
            numMinus++;
            numSet.push_back(temp);
        }
        else{
            numPlus++;
            numSet.push_back(temp);
        }
    }
    total = one;
    sort(numSet.begin(), numSet.end());
    // 음수부분 처리
    for(int i = 0 ; i < numMinus; i+=2){
        //마지막에 한 개 남았을 때
        if(i == numMinus-1){
            if(zero > 0)
                break;
            else total+=numSet[i];
        }else
            total += (numSet[i]*numSet[i+1]);

    }
    // 양수부분
    if(numPlus%2==1) total += numSet[numMinus];
    for(int i = (numPlus%2==1)?1:0; i < numPlus; i+=2){
        total += (numSet[numMinus+i]*numSet[numMinus+i+1]);
    }
    cout << total << endl;
}