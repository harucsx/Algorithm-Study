//
// Created by John on 2017-03-05.
//
#include <iostream>
#include <vector>

using namespace std;

void findSol(vector<int> a, vector<int> b) {

}

int main(){
    int T;
    cin>>T;
    int num_a, num_b;
    cin>>num_a>>num_b;

    vector<int> a;
    vector<int> b;

    int tmp;
    for (int i = 0; i < num_a; ++i) {
        cin>>tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < num_b; ++i) {
        cin>>tmp;
        b.push_back(tmp);
    }
    findSol(a, b);


}
