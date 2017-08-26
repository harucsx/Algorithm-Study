//
// Created by HANLEEKYEUNG on 2017. 2. 20..
//

#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(st, ed) for(int i = st ; i < ed; i++)
#define MAX_COIN    5000

using namespace std;

// 변수선언
int tc, target, numCoin;
vector<int> coins;
int cache[MAX_COIN] = {0, };

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
        cin >> target;
        cin >> numCoin;
        coins.clear();  //벡터 초기화

        FOR(0, numCoin){
            int input;
            cin >> input;
            coins.push_back(input);
        }

        sort(coins.begin(), coins.end(), comp); //벡터 정렬

//        print(coins);

        for(int k=0; k<numCoin; k++){
            if(target < coins[k]) break;
            cache[coins[k]]++;

            for (int j = 1; coins[k] + j <= target; j++)
            {
                if (cache[j] >= 0)
                    cache[j + coins[k]] = sum1007(cache[j + coins[k]], cache[j]);
            }
        }

        cout << cache[target] << '\n';

        FOR(0, target+1) cache[i] = 0;

    }
    return 0;
}
