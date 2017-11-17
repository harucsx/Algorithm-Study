//
// Created by HANLEEKYEUNG on 2017. 11. 16..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> router;
bool check(int length){
    int last = router.front();
    int count = 1;
    while(true){
        if(last + length > router.back()) return false;
        int next = *(lower_bound(router.begin(), router.end(),last+length));
//        if(next > last + length) next = *(&next+1);
//        cout << next << " ";
        count++;
        last = next;
        if(count >= c) return true;
    }

}
int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d %d",&n, &c);
    router.resize(n);
    for(int i =0 ; i < n; i ++){
        scanf("%d",&router[i]);
    }
    sort(router.begin(), router.end());
//    for(int x : router) cout << x << " ";
//    cout << endl;
    long long l = 0, r=router.back()/c+1, mid, ans=0;
    while(l<=r){
        mid = (l+r)/2;
//        cout <<"["<< mid <<"] ";
        if(check(mid)){
            ans = max(ans, mid);
            l = mid +1;
        }
        else r = mid -1;
//        cout << endl;
    }
    cout << ans << endl;
}