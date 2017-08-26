//
// [예제 통과, algospot 제출시 시간초과]
//
#include <iostream>

using  namespace std;

void findSol(string &mem, string &fan, int fan_first, int fan_last, int &sol, int set[]) {
    int mem_size = mem.size();
    int fan_mid = (fan_first + fan_last) / 2;
    int mem_mid = (0 + mem.size() - 1)/2;

    if(set[fan_mid])
        return;
    set[fan_mid] = 1;

    int count = 0;
    for (int i = 0; i < mem_size; ++i) {
        if(fan_mid - mem_mid + i < 0 || fan_mid - mem_mid + i >= fan.size())
            break;
        if((mem[i] == 'M' && fan[fan_mid - mem_mid + i] == 'F') || mem[i] == 'F')
            count++;
    }
    if(count == mem_size) sol++;

    findSol(mem, fan, fan_first, fan_mid, sol, set);

    findSol(mem, fan, fan_mid + 1, fan_last, sol, set);

    return;
}

int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        string fan;
        string member;

        cin>>member;
        cin>>fan;

        int set[200000] = {0, };
        int fan_first = 0;
        int fan_last = fan.size() - 1;
        int sol = 0;
        findSol(member, fan, fan_first, fan_last, sol, set);
        cout<<sol<<endl;
    }
}