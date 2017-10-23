//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(var, ed) for(int var = 0; var < ed; var++)
using namespace std;
vector<pair<char, int>> expression;
int main(){
//    freopen("input.txt", "r", stdin);
    expression.clear();
    int num;
    char plus;

    // first element
    scanf("%d", &num);
    expression.push_back(make_pair('+', num));
    //from second element
    while(true){
        scanf("%c", &plus);
        if(plus != '+' && plus != '-') break;
        scanf("%d", & num);
        expression.push_back(make_pair(plus, num));
    }
    // +인것들은 묶음
    for(int index = expression.size()-1; index>=1; index--){
        if(expression[index].first == '+'){
            expression[index-1].second+=expression[index].second;
            expression.erase(expression.begin()+index);
        }
    }
    // 남은 식 계산
    int ret = expression[0].second;
    for(int i = 1; i < expression.size(); i++){
        ret -= expression[i].second;
    }
    cout << ret << endl;

}
