//
// Created by HANLEEKYEUNG on 2017. 11. 16..
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m;
vector<pair<int,int>> bridge[10001]; // * 자료구조 참고함
bool visited[100001];
int st, ed;

bool able(int weight, int last){
    if(visited[last]) return false;
    visited[last] = true;
//    cout << "here" << endl;

    if(last == ed) return true;
    for(auto p : bridge[last]){
        int next = p.first;
        int cost = p.second;
//        cout << last << " " << next << " " << cost << endl;
        if(cost>=weight){
            if(able(weight, next)) return true;
        }
    }
    return false;
//    // original code
//    for(pair<int,int> s: bridge[last]){
//        if(!visited[s.first] && s.second >= weight){
//            visited[s.first] = 1;
//            if(able(weight, s.first)) return true;
//            visited[s.first] = 0;
//        }
//    }
//    return false;
}
int main(){
//    freopen("input.txt","r",stdin);

    //get input
    scanf("%d %d",&n,&m);
    int a, b, temp;
    long long l=0, r=0, mid, ans=0;
    for(int i = 0 ;i  < m; i++) {
        scanf("%d %d", &a, &b);
        scanf("%d", &temp);
        bridge[a].push_back(make_pair(b,temp));
        bridge[b].push_back(make_pair(a,temp));
        if(temp>r) r=temp;
    }

    scanf("%d %d",&st, &ed);

    while(l<=r){
        mid = (l+r)/2;
//        cout << mid << endl;
        memset(visited, false, sizeof(visited));
        if(able(mid, st)){
            ans = max(ans, mid);
            l = mid+1;
        }else r = mid-1;
    }
    // solve
    cout << ans << endl;

}