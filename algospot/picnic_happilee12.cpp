//
// Created by HANLEEKYEUNG on 2017. 1. 25..
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int makePair(bool matched[10], bool pair[10][10], int numPeople){
    int p1 = -1;
    int result = 0;
    for(int i=0; i<numPeople; i++){
        if(!matched[i]){
            p1 = i;
            break;
        }
    }
    if(p1 == -1){
        return 1;
    }
    for(int p2 = p1+1; p2<numPeople; p2++){
        if(!matched[p2] && pair[p1][p2]){
            matched[p1] = matched[p2] = true;
            result += makePair(matched, pair, numPeople);
            matched[p1] = matched[p2] = false;
        }
    }

    return result;
}

int main(){
    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int i=0; i<tc; i++){
        bool matched[10];
        bool pair[10][10];
        int numPeople, numPair;

        cin >> numPeople >> numPair;
        memset(matched, 0, 10);
        memset(pair, 0, 100);

        for(int j = 0; j<numPair; j++){
            int p1, p2;
            cin >> p1 >> p2;

            pair[p1][p2] = pair[p1][p2] = true;
        }

        cout << makePair(matched, pair, numPeople) << endl;
    }
}