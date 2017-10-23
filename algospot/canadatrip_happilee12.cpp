//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(var, ed) for(int var = 0 ; var < ed; var++)
using namespace std;

int tc, n, k;
int l[5000], m[5000], g[5000];
void input(){
    cin >> n >> k;
    FOR(i, n){
        cin >> l[i] >> m[i] >> g[i];
    }
}

//dist까지 지나면서 K개 이상의 표지판을 볼 수 있는가
bool decision(int dist){
    int ret = 0;
    for(int i = 0; i < n ; i++){
        // i번째 도시의 표지판을 하나 이상 보는가
        if(dist >= l[i]-m[i])
            // i번째 도시의 표지판을 몇 개 보는지
            ret += (min(dist, l[i]) - (l[i]-m[i]))/ g[i]+1;
    }
//    cout << dist << " : " << ret << endl;
    return ret >= k;
}
// k번째 표지판을 만나는 위
int optimize(){
    // 반복 불변식 !decision(low) && decision(high)
    int lo = -1, hi = 8030001;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(decision(mid))   hi = mid;
        else lo = mid;
    }
    return hi;
}
int main(){
//    freopen("input.txt","r",stdin);
    cin >> tc;
    while(tc--){
        input();
        cout << optimize() << endl;
    }
}