//
// Created by HANLEEKYEUNG on 2017. 10. 19..
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)
using namespace std;

int tc, n, m, people;
string temp;
vector<long long int> allergic;
vector<string> names;
int best;
long long int full;
void getInput(){
    cin >> n >> m;
    names.clear();
    names.resize(n);
    allergic.clear();
    allergic.reserve(m);
    full = (1LL<<n)-1;//**비트연산자 int넘어갈때
//    cout << bitset<50>(full) << endl;
    FOR(i, n){
        cin >> names[i];
    }
    //for each food
    FOR(food, m){
        cin >> people;
        long long int bit = 0;
        FOR(j, people){
            cin >> temp;
            FOR(k, n){
                if(!strcmp(temp.c_str(), names[k].c_str())) {  //**strcmp 사용법
                    bit += (1LL << k);
                    break;
                }
            }
        }
        allergic[food] = bit;
//        cout << bitset<50>(allergic[food]) << endl;
    }

//    FOR(i, m)
//        cout << bitset<20>(allergic[i]) << endl;

}
void solve(long long int a, int sum, int index){
//    cout << bitset<50>(a) <<" "<<sum <<"index : "<< index << endl;
    if(sum >= best) return;
    if(a==full){
        best = min(best, sum);
//        cout << "best updated to ... " <<  best << endl;
    }
    if(index == m) return;
    // index물건 넣음
//    cout << index << " 넣음--" << endl;
    solve(a|allergic[index], sum+1, index+1);
    //index 안 넣음
//    cout << index << " 안넣음--" << endl;
    solve(a, sum, index+1);
}
int main(){
//    freopen("input.txt","r",stdin);
    cin >> tc;
    while(tc--){
        getInput();
        best = 51;
        solve(0, 0, 0);
        cout << best << endl;
    }
}