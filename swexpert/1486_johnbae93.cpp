//
// Created by John on 2017-09-01.
//
#include <iostream>
#include <cstdio>

using namespace std;

int arr[20];
int n, tall;
int tall_min = 0x7fffffff;

void dfs(int index, int sum) {
    if (sum >= tall) {
        if(sum < tall_min)
            tall_min = sum;
        return;
    }

    if(index >= n)
        return;

    dfs(index+1, sum+arr[index]);
    dfs(index+1, sum);

}

int main(){
    freopen("input.txt", "r", stdin);
    int T;

    cin>>T;

    for (int i = 0; i < T; ++i) {
        cin>>n>>tall;
        for (int j = 0; j < n; ++j) {
            cin>>arr[j];
        }
        dfs(0,0);
        cout<<'#'<<i+1<<' ';
        cout<<tall_min-tall<<endl;
        tall_min = 0x7fffffff;
    }

}

