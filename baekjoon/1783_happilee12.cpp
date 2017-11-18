//
// Created by HANLEEKYEUNG on 2017. 10. 25..
//

#include <iostream>
using namespace std;

int height, width, ret;
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> height >> width;
    if(height == 1) ret = 1;
    else if(height == 2) ret = min(4, (width+1)/2);
    else{
        if(width>=7){
            ret = width-2;
        }
        else ret = min(4, width);
    }


    cout << ret << endl;
}