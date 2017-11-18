//
// Created by HANLEEKYEUNG on 2017. 11. 15..
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long k, n;
vector<long long> lan;
bool possible(long long length, long long num){
    long long count = 0;
    for(long long x : lan)
        count += (x/length);
    if(count >= num) return true;
    else return false;
}
void bs(long long max, long long num){
    long long st = 0, ed = max+1, mid;
    while(st<=ed){
        if(mid == (st+ed)/2) break;
        else mid = (st+ed)/2;
//        cout << mid << endl;
        if(possible(mid, num)) st = mid;
        else ed = mid;
    }
    cout << mid << endl;
}
int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d %d\n",&k, &n);
    lan.resize(k);
//    cout << k << " " << n << endl;
    for(long long i = 0 ; i < k ; i++) scanf("%d\n",&lan[i]);
//    cout << *max_element(lan.begin(), lan.end()) << endl;
    bs(*max_element(lan.begin(), lan.end()), n);
}