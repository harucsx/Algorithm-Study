//
// Created by HANLEEKYEUNG on 2017. 11. 17..
//

#include <iostream>
#include <algorithm>
#define  FOR(var, n) for(int var  = 0 ; var < n; var++)
using namespace std;
int n, m, one[1000000], two[1000000], merged[2000000];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
//    cout<< "here" << endl;

    FOR(i, n) scanf("%d ",&one[i]);
//    FOR(i, n) printf("%d ",one[i]);
    FOR(i, m) scanf("%d ",&two[i]);
//    FOR(i, m) printf("%d ",two[i]);
    int oleft =0, tleft=0, curindex=0;
    while(oleft<n || tleft<m){
        if(oleft==n){
            while(tleft<m)
                merged[curindex++] = two[tleft++];
        }
        else if(tleft==m){
            while(oleft<n)
                merged[curindex++] = one[oleft++];
        }
        else if(one[oleft]<two[tleft])
            merged[curindex++] = one[oleft++];
        else
            merged[curindex++] = two[tleft++];
    }

    FOR(i, curindex){
        printf("%d ",merged[i]);
    }
}