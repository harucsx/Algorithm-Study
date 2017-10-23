//
// Created by HANLEEKYEUNG on 2017. 10. 24..
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, ed) for(int i = 0; i < ed; i++)

int n, temp, total=0;
char od;
bool possible = false;
vector<int> digit;
vector<int>::iterator it;
int main(){
//    freopen("input.txt", "r", stdin);
    while(true){
        scanf("%c", &od);
        if(od < '0' || od > '9') break;
        int temp = od-'0';

        if(temp == 0) possible = true;
        total += temp;
        digit.push_back(temp);
    }


    // 자릿 수 중 0 이 없으면 어차피 30의 배수를 만들 수 없음
    if(!possible){
        cout << "-1" << endl;
        return 0;
    }
    // 0하나 썼으니깐 지움
    it = find(digit.begin(), digit.end(), 0);
    digit.erase(it);

    // 3의배수를 만들 수 있을지 확인
    if(total %3 !=0){
        cout << "-1" << endl;
        return 0;
    }

    // 나머지로 최대의 3의 배수를 만듬
    sort(digit.begin(), digit.end());
    for(int i = digit.size()-1; i>=0; i--)
        cout << digit[i];
    cout << '0';
    cout << endl;
}