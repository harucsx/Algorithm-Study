//https://algospot.com/judge/problem/read/RESTORE
//오답

#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#define FOR(i, ed) for(int i = 0 ; i < ed; i++)
#define MINF std::numeric_limits<int>::min(); //*
using namespace std;

// input
int tc, k;
vector<string> piece;
//algorithm
int commonLength[16][16];
int cache[16][1<<16]; //j상태일 때 i에서부터 얻을수 있는 최대
void printcommonLength(){
    FOR(i, k) {
        FOR(j, k)
            cout << commonLength[i][j] << " ";
        cout << endl;
    }
}
void print(vector<string> &a) {
for (string x : a) {
cout << x << ' ';
}
cout << '\n';
}
void cleansubstr(){
    int erase = 0;
    for(int i = 1; i<k; i++){
        FOR(j, i){
            if(piece[j].find(piece[i]) != string::npos){
                piece.erase(piece.begin()+i);
                i--;
                k--;
                break;
            }else if(piece[i].find(piece[j]) != string::npos){
                piece.erase(piece.begin()+j);
                i--;
                j--;
                k--;
            }
        }
    }
}

int calcCommon(int i , int j){
    for(int common = min(piece[j].length(),piece[i].length()); common >0; common--){
        FOR(index, common){
            if(piece[i][piece[i].length()-common+index] != piece[j][index]) break;
            if(index == common-1) return common;
        }
    }
    return 0;

}
void precalc(){
    //string i 뒤에 string j를 이어붙일 때 겹치는 길이
    FOR(i, k){
        FOR(j, k){
            if(i==j) continue;
            else commonLength[i][j] = calcCommon(i, j);
        }
    }
}

int play(int here, int visited){
    if(visited == (1<<k)-1) return 0;
    int &ret = cache[here][visited];
    if(ret >0) return ret;
    ret = MINF;
    FOR(next, k){
        if(visited & (1<<next)) continue;
        ret = max(ret, commonLength[here][next]+play(next, visited+(1<<next))); // *
    }
    return ret;
}
string reconstruct(int here, int visited){
    if(visited == (1<<k)-1) return "";
    FOR(next, k){
        if(visited & (1<<next)) continue;
        int ifUsed = commonLength[here][next]+play(next, visited+(1<<next));
        if(play(here, visited) == ifUsed){
//            cout << next << endl;
            return piece[next].substr(commonLength[here][next])+reconstruct(next, visited+(1<<next));
        }
    }
    return "**";
}

int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        piece.clear();
        memset(commonLength, 0, sizeof(commonLength));
        memset(cache, -1, sizeof(cache));
        cin >> k;
        FOR(i, k){
            string temp;
            cin >> temp;
            piece.push_back(temp);
        }
        cleansubstr();
//        print(piece);
        precalc();
//        printcommonLength();
        int rslt = MINF;
        int start;
        FOR(i, k){
            int temp = play(i, 1<<i);
            if(rslt <= temp){
                rslt = temp;
                start = i;
            }
        }
//        cout << play(start, 1<<start) << endl;
        cout << piece[start]+reconstruct(start, 1<<start) << endl;
    }
}


