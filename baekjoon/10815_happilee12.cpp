//
// Created by HANLEEKYEUNG on 2017. 11. 15..
//

#include <iostream>
#include <vector>
#include <algorithm>
#define  FOR(i, ed) for(int i = 0 ; i < ed; i++)
using namespace std;

int m, n, target;
vector<int> card;
//int card[500000];
void getinput(){
    scanf("%d ",&m);
    card.resize(m);
    FOR(i, m) scanf("%d ",&card[i]);
    scanf("%d ",&n);
}
int bs(int target){
    //binary search the "card" vector for "target"
    int st = 0, ed = m-1, mid;
    if(card[st] == target || card[ed]==target) return 1;

    while(st < ed-1){
        mid = (st+ed)/2;
        if(target < card[mid])
            ed = mid;
        else st = mid;
        if(card[st] == target || card[ed]==target) return 1;
    }
    return 0;
}
int bs2(int target){
    int st = 0, ed = m-2, mid;
    while(st <= ed){
        mid = (st+ed)/2;
        if(card[mid]==target) return 1;
        // it's not at [mid] anyway
        if(card[mid]<target) st = mid+1;
        else ed = mid-1;
    }
    return 0;
}
void solve() {
    // sort the card
//    sort(card,card+n);
    sort(card.begin(), card.end());
    FOR(i, n) {
        scanf("%d ", &target);
        printf("%d ",bs2(target));
//        printf("%d ",binary_search(card,card+n,target));
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    getinput();
    solve();
}
