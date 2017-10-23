//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
using namespace std;

int n, m, k; // n:여학생  m: 남학생 k: 인턴
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    int totalPeople = n+m;
    int maxTeam = min(n/2, m);
    while(true){
        if(totalPeople-maxTeam*3 >= k) break;
        maxTeam--;
    }
    cout << maxTeam << endl;
}