//
// Created by John on 2017-03-05.
//
// 책과는다르게 앞에서부터 안하고 뒤에서부터 dp 적용함
//
#include <iostream>
#include <vector>

using namespace std;

void findSol(vector<int> &v, int mem[500], int index){
    if(index < 0) return;
    if(index == v.size() - 1) {
        mem[v.size() - 1] = 1;
        findSol(v, mem, index - 1);
        return;
    }
    mem[index] = 1;
    int max = 0;
    for (int i = index + 1; i < v.size(); ++i) {
        if(v[index] < v[i] && mem[i] > max) max = mem[i];
    }
    mem[index] = max + 1;
    findSol(v, mem, index - 1);
    return;
}

int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        int num;
        cin>>num;
        vector<int> v;
        //vector<int> mem;

        for (int j = 0; j < num; ++j) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        //mem.reserve(v.size());
        int mem[500] = {0, };
        findSol(v, mem, v.size() - 1);
        int sol = 0;
        for (int k = 0; k < v.size(); ++k) {
            if(mem[k] > sol)
                sol = mem[k];
        }
        cout<<sol<<endl;
    }
}
