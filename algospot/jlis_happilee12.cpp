//
// Created by HANLEEKYEUNG on 2017. 1. 26..
// 굉장히 비효율적이어 보이는데 왜 시간초과가 안나는지 의문임
//

// subp[n][m]을 찾는다면
//subp[n-1][m]에서 n을 추가하는 경우와
//subp[n][m-1]에서 m을 추가하는 경우로 나뉨
//subp[n-1][m]에서 n을 추가하는 경우를 예로 들면
//1. n-1까지 중에서 추가되는 값보다 작은 값을 찾고
//2. 반대쪽 행에서 겹치는 값이 있는지 확인한후
// 3. 겹치는게 있다면 그대로 없다면 +1 을 함


#include<iostream>
#include<vector>
using namespace std;

int seek(int subp[100][100], int a[], int b[], int x, int y){
    int max1 = 1;
    int max2 = 1;
    int temp;
    for(int p = x; p>=0; p--){
        //a쪽 행 탐색
        if(a[p] < a[x]){
            bool overlap = false;
            // b쪽에 겹치는게 있는지 여부 확인
            for(int q = y; q>=0; q--){
                if(b[q] < a[x])  break;
                if(b[q] == a[x]) {
                    overlap = true;
                }
            }
            if(overlap)
                temp = subp[p][y]-1;
            else
                temp = subp[p][y];

            if(temp > max1) max1 = temp;
        }
    }
    for(int q = y; q>=0; q--){
        //b쪽 행 탐색
        if(b[q] < b[y]){
            bool overlap = false;
            // a쪽에 겹치는게 있는지 여부 확인
            for(int p = x; p>=0; p--){
                if(a[p] < b[y])  break;
                if(a[p] == b[y]) {
                    overlap = true;
                }
            }
            if(overlap)
                temp = subp[x][q]-1;
            else
                temp = subp[x][q];
//            break;
            if(temp > max2) max2 = temp;
        }
    }
    return max(max1, max2);
}
int dp(int subp[100][100], int a[], int b[], int lena, int lenb){
    int max = 0;
    for(int y = 0; y<lenb; y++){
        for(int x = 0; x<lena; x++){
            if(y == 0 && x == 0){
                if(a[0] == b[0]) subp[0][0] = 1;
                else subp[0][0] = 2;
            }
            else {
                subp[x][y] = seek(subp, a, b, x, y) + 1;
            }
            if(max < subp[x][y]) max = subp[x][y];
        }
    }

    return max;
}

int main() {
    vector <int> list;
    int c;
    cin >> c;
    int lena, lenb;

    while (c-- > 0) {
        scanf(" %d %d",&lena, &lenb);
        int subp[100][100] = {0, };
        int a[100] = {0, };
        int b[100] = {0, };

        for(int i = 0; i<lena; i++)
            scanf(" %d", &a[i]);
        for(int i = 0; i<lenb; i++)
            scanf(" %d", &b[i]);

        cout << dp(subp, a, b, lena, lenb) << endl;
    }
}
