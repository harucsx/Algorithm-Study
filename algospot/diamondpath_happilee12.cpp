//
// Created by HANLEEKYEUNG on 2017. 2. 20..
// 난이도 : 무난
//

#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(i, st, ed) for(int i = st ; i < ed; i++)

using namespace std;

// 변수선언
int tc, mid, input;
int cache[101] = {0, };
int currentInput[101] = {0, };

int bigger(int a, int b){
    if (a>b) return a;
    else return b;
}
int main(void){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    FOR(i, 0, tc){
        cin >> mid;
        FOR(j, 0, mid){
            FOR(k, 0, j+1){
                cin >> input;
                currentInput[k] = input + bigger(cache[k-1], cache[k]);
            }
            FOR(k, 0, j+1){
                cache[k] = currentInput[k];
//                cout << cache[k] << ' ';
            }
//            cout << "\n";
        }
        currentInput[mid-1] = 0;
        for(int j = mid-2; j>=0; j--){
            FOR(k, 0, j+1){
                cin >> input;
                currentInput[k] = input + bigger(cache[k+1], cache[k]);
            }
            FOR(k, 0, j+1){
                cache[k] = currentInput[k];
//                cout << cache[k] << ' ';
            }
//            cout << "\n";

            cache[j+1] = 0;
            currentInput[j+1] = 0;
        }
        cout << cache[0] << "\n";
        cache[0] = 0;
        currentInput[0] = 0;

    }

    return 0;
}
