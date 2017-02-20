//
// Created by John on 2017-02-13.
//
#include <iostream>
#include <string>

using  namespace std;

string findSol(string::iterator &v) {
    char current = *v;
    v++;

    if(current == 'w' || current == 'b')
        return string(1, current);

    string first = findSol(v);
    string second = findSol(v);
    string third = findSol(v);
    string fourth = findSol(v);

    return string("x") + third + fourth + first + second;

}


int main(){
    int T;
    int test_case;

    cin>>T;
    for (test_case = 0; test_case < T; test_case++) {
        string v;

        cin>>v;

        string::iterator j;

        j = v.begin();
        string sol = findSol(j);
        cout<<sol<<endl;

    }
}