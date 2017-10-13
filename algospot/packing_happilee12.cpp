//
// Created by HANLEEKYEUNG on 2017. 9. 27..
// Updated on 2017. 10. 12
//
//https://algospot.com/judge/problem/read/PACKING

#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i, ed) for(int i = 0 ; i < ed; i++)

using namespace std;

int tc;
// input
int maxVol;
int numProduct;
string product[100];
int volume[100];
int need[100];
// for process
int cache[1001][100]; // index 이후의 물건들로 maxVol을 채울 때 최대 절박도
vector<string> packed; //마지막에 가방에 담은 아이템들을 저장할 벡터

//cache[maxVol][index]값을 찾아서 반환하는 함수
int play(int index, int maxVol){
    if(index == numProduct) return 0;
    int& ret = cache[maxVol][index]; // index 이후의 물건들로 maxVol을 채울 때 최대 절박도
    if(ret != -1) return ret;
    ret = play(index+1, maxVol);
    if(volume[index]<=maxVol)
        ret = max(ret, play(index+1, maxVol-volume[index])+need[index]);
    return ret;
}
void reconstruct(int index, int maxVol){
    if(index == numProduct) return;
    if(play(index, maxVol) == play(index+1, maxVol))
        return reconstruct(index+1, maxVol);
    packed.push_back(product[index]);
    return reconstruct(index+1, maxVol-volume[index]);
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        packed.clear(); //packed 벡터 초기화
        memset(cache, -1, sizeof(cache)); // cache배열을 -1로 초기화
        cin >> numProduct >> maxVol;
        FOR(i, numProduct)
            cin >> product[i] >> volume[i] >> need[i];
        cout << play(0, maxVol) << " ";
        reconstruct(0, maxVol);
        cout << packed.size() << endl;
        FOR(i, packed.size())
            cout << packed[i] << endl;
    }
}