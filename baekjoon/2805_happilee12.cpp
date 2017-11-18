//
// Created by HANLEEKYEUNG on 2017. 11. 16..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
vector<long long> tree;
bool check(long long cutoff){
    long long total = 0;
    for(long long x : tree){
        if(x-cutoff > 0)
            total += (x-cutoff);
    }
    return total>=m;
}
long long bs(){
    long long st = 0, ed = *max_element(tree.begin(), tree.end()), mid; // *+1하는거
    long long ans = 0;
    while(st <=ed){
        mid = (st+ed)/2;
//        cout << mid << endl;
        // if it is possible to make the length "m" with "mid" cutoff
//        if(check(mid)){
//            ans = max(ans, mid);
//            st = mid+1;
//        }else{
//            ed = mid-1;
//        }
        if(mid == (st+ed)/2) break;
        mid = (st+ed)/2;
        if(check(mid)) st = mid;
        else ed = mid-1;
    }
    return ans;
}
int main(){
//    freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n, &m);
    tree.resize(n);
    for(int i = 0; i < n ; i ++)
        scanf("%lld ",&tree[i]);
    cout << bs() << endl;

}