//
// Created by John on 2017-02-23.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int findSol(string &w, set<string> &v) {

    if(NULL
}

int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        string w;
        cin>>w;

        int num;
        cin>>num;

        set<string> v;
        for (int j = 0; j < num; ++j) {
            string s;
            cin>>s;
            v.insert(s);
        }
        findSol(w, v);
    }
}