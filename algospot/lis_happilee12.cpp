//
// Created by HANLEEKYEUNG on 2017. 2. 19..
//

#include<iostream>
#include <string.h>
#include <vector>
#include <limits.h>
// memset (target, char, num)

using namespace std;

int tc, size;
vector<int> input;
vector<int> cache;

void print(vector<int> &a){
    for(int x : a){
        cout << x << " ";
    }
    cout << endl;
}
int main(void){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    for(int i = 0; i < tc; i ++){
        input.clear();
        cache.clear();
        int size;
        int cinnum;
        cache.push_back(INT_MAX);
        cin >> size;
        for(int j = 0 ; j < size; j ++) {
            cin >> cinnum;
            input.push_back(cinnum);
            //입력

            for(auto it = cache.begin(); it != cache.end(); it++){
                if(cinnum < *it) {
                    *it = cinnum;
                    break;
                }
                if(it == cache.end()-1 && cinnum > *it)
                    cache.push_back(cinnum);
            }

        }
        cout << cache.size() << endl;

    }

}
