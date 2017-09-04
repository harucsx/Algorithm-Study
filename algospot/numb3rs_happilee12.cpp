//
// Created by HANLEEKYEUNG on 2017. 8. 29..
//

//
// 문제 : NUMB3RS (https://algospot.com/judge/problem/read/NUMB3RS)
// 난이도 : 중하? 메모리 0으로 초기화하는거에서 계속 틀림!!!!!!!!!!!!!!
//

#include<iostream>
//for memset
#include <string.h>

#define maxVillage 50
#define FOR(var, max) for(int var = 0; var < max; var++)

using namespace std;

// declare variables
int testCases, numOfVillage, prison, days, numOfCalProb;
int townMap[maxVillage+1][maxVillage+1] = {0, };

double probMatrix[maxVillage+1][maxVillage+1] = {0, };
double nTimesProbMatrix[maxVillage+1][maxVillage+1] = {0, };

// declare functions
// Multiply Square matrix N times
void probMatrixMul(int n, int villages){

    if(n > 0) {
//        cout << "n = " << n << " villages = " << villages << "\n";
        double cacheMatrix[maxVillage + 1][maxVillage + 1] = {0,};
        FOR(row, villages) {
            FOR(col, villages) {
                double result = 0;
                FOR(seq, villages) {
                    result += (nTimesProbMatrix[row][seq] * probMatrix[seq][col]);
                }
                cacheMatrix[row][col] = result;
            }
        }
        FOR(row, villages) {
            FOR(col, villages) {
                nTimesProbMatrix[row][col] = cacheMatrix[row][col];
//                cout << cacheMatrix[row][col] <<" ";
            }
//            cout << endl;
        }
    }
    if(n>1)
        return probMatrixMul(n-1, villages);
    else
        return;
}


int main(){
//    freopen("input.txt", "r", stdin);
    cin >> testCases;
    cout.precision(9);

    FOR(tc, testCases){
        cin >> numOfVillage;
        cin >> days;
        cin >> prison;
        FOR(row, numOfVillage){
            int numConnect = 0;
            FOR(col, numOfVillage){
                int input;
                cin >> input;
                townMap[row][col] = input;
                if(input == 1) numConnect ++;
            }
            FOR(col, numOfVillage){
                if(townMap[row][col] == 1){
                    probMatrix[row][col] = 1.0/numConnect;
                    nTimesProbMatrix[row][col] = 1.0/numConnect;
                }
            }
        }

        probMatrixMul(days - 1, numOfVillage);

        cin >> numOfCalProb;
        FOR(i, numOfCalProb){
            int input;
            cin >> input;
            cout << nTimesProbMatrix[prison][input] << " ";
        }cout << "\n";


        //cache reset
        memset(townMap, 0, 52*52);
        memset(probMatrix, 0, 52*52);
        memset(nTimesProbMatrix, 0, 52*52);
        FOR(row, numOfVillage){
            FOR(col, numOfVillage) {
                townMap[row][col] = 0;
                probMatrix[row][col] = 0;
                nTimesProbMatrix[row][col] = 0;
            }
        }
    }
}
