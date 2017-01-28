//
// Created by HANLEEKYEUNG on 2017. 1. 26..
//


#include <iostream>
using namespace std;

string reverse(string &input, string output){
//    cout << input << endl;
    string first = {};
    string next = {};
    if(input.length()==1) return input;

    if (input[0] == 'b' || input[0] == 'w') {
        string s(1, input[0]);
        output.append(s);
        input.erase(0,1);
        return output;
    }
    else{
        output.append("x");
        input.erase(0,1);
        first.append(reverse(input, ""));
        first.append(reverse(input, ""));
        next.append(reverse(input, ""));
        next.append(reverse(input, ""));
        output.append(next).append(first);
        return output;
    }
}
int main(){
//    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d ",&tc);
    for(int i=0; i<tc; i++){
        string output;
        string input;
        getline(cin, input);
        output = reverse(input, "");
        cout << output << endl;
    }
}