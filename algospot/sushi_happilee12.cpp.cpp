//
// Created by HANLEEKYEUNG on 2017. 9. 9..
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//define
#define FOR(var, num) for(int var=0; var<num; var++)

int numSushi, maxBudget;
int menu[20][2];
int cache[201];

//int cache[21474837]; // 해당 돈으로 얻는 최고 만족도
//int dp(int budget){
//    if(cache[budget] != -1) return cache[budget];
//
//    int& ret = cache[budget];
//    ret = 0;
//    FOR(index, numSushi){
//        // 지금 돈으로 얻는 최고 만족도는
//        // 지금 돈으로 살수 있는 것의 만족도 + (지금 돈 - 방금 산 쓰시 가격)으로 살 수 있는 것의 만족도
//        if(budget-menu[index][0] >= 0)
//            ret = max(ret, menu[index][1] + dp(budget - menu[index][0]));
//    }
//    return ret;
//}
// *** Process finished with exit code 11
int dp() {
    int ret = 0;
    cache[0] = 0;
    FOR(current, maxBudget+1){
        int temp = 0;
        FOR(sushi, numSushi){
            if(current >= menu[sushi][0])
                temp = max(temp, menu[sushi][1]+cache[(current-menu[sushi][0])%201]);
        }
        cache[current%201] = temp;
        ret = max(ret, temp);
    }
    return ret;
}

int main(){
//    freopen("input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cin >> numSushi;
        cin >> maxBudget;
        //clear cache
        FOR(i, 201){
            cache[i] = -1;
        }
//        FOR(i, 21474837){
//            cache[i] = -1;
//        }
        maxBudget /= 100;
        FOR(i, numSushi){
            cin >> menu[i][0];
            menu[i][0] /= 100; // price
            cin >> menu[i][1]; // satisfy
        }
//        FOR(i, numSushi){
//            cout << menu[i][0] << endl;
//            cout << menu[i][1] << endl; // satisfy
//        }
//        cout << dp(maxBudget) << endl;
        cout << dp() << endl;
    }

    return 0;
}

