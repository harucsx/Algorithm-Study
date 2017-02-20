//
// Created by HANLEEKYEUNG on 2017. 2. 20..
//

#include<iostream>
#include<vector>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
// memset (target, char, num)
#define FOR(i, st, ed) for(int i = st ; i < ed; i++)
using namespace std;

vector<int> input;
vector<int> sum;
vector<double> squaresum;
int memoize[101][101];
int rslt[101][101];
double error(int st, int ed){
    double sq = squaresum[ed] - squaresum[st];
    double sm = sum[ed] - sum[st];
    int mn = (int)floor((sm / (ed - st))+0.5);
    return (sq - 2*mn*sm + (ed-st)*pow(mn, 2));
}

int main(void){
//    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d ",&tc);
    while(tc-- > 0){
        int size, quant;
        cin >> size;
        cin >> quant;
        input.clear();
        sum.clear();
        squaresum.clear();
        memset(memoize, 0, 101*101);
        memset(rslt, 0, 101*101);

        //input & sort
        int temp;
        input.push_back(0);
        sum.push_back(0);
        squaresum.push_back(0);
        FOR(i, 0, size){
            cin >> temp;
            input.push_back(temp);
        }
        sort(input.begin(), input.end());
        FOR(i, 1, size+1) {
            sum.push_back(sum.back() + input[i]);
            squaresum.push_back(squaresum.back() + pow(input[i], 2));
        }

        //i부터 j까지를 하나로 묶었을 때의 오차를 memoize에 저장
        FOR(i, 1, size+1){
            FOR(j, i, size+1){
                memoize[i][j] = error(i-1, j);
            }
        }

        //답구하기
        FOR(j, 1, size+1){
            rslt[1][j] = memoize[1][j];
        }
        FOR(i, 2, size+1){
            FOR(j, i, size+1){
                //rslt[i][j] 를 구하려면
                int mem = INT_MAX;
                FOR(k, i-1, j){
                    if(mem > rslt[i-1][k]+memoize[k+1][j]) mem = rslt[i-1][k]+memoize[k+1][j];
                }
                rslt[i][j] = mem;
            }
        }
        cout<< rslt[quant][size] << endl;
    }
    return 0;
}