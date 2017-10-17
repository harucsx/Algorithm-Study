//
// Created by HANLEEKYEUNG on 2017. 10. 17..
//

#include <iostream>
#include <algorithm>

#define FOR(var, ed) for(int var = 0; var<ed; var++)
using namespace std;

//input
int tc, n;
int russia[100], korea[100];
int play(int r, int k){
    if(r==n || k==n) return 0;
    if(korea[k]>= russia[r])
        return 1+play(r+1, k+1);
    else
        return play(r, k+1);
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        cin >> n;
        FOR(i, n)
            cin >> russia[i];
        FOR(i, n)
            cin >> korea[i];
        sort(russia, russia+n);
        sort(korea, korea+n);
        cout << play(0,0) << endl;
    }
}
