//
// Created by HANLEEKYEUNG on 2017. 10. 19..
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)
using namespace std;

int tc, r, c, br, bc, empty;
vector<string> iboard;
vector<string> block;
vector<vector<pair<int,int>>> rotations;
int board[10][10];
int blocksize;
int best;
void getInput(){
    iboard.clear();
    memset(board, 0, sizeof(board));
    block.clear();
    string temp;
    cin >>r>>c>>br>>bc;
    empty = r*c;
    FOR(i, r){
        cin >> temp;
        iboard.push_back(temp);
    }
    FOR(i, r){
        FOR(j, c){
            if(iboard[i][j] == '#'){
                board[i][j]=1;
                empty--;
            }
        }
    }
    FOR(i, br){
        cin >> temp;
        block.push_back(temp);
    }
}
vector<string> rotate(vector<string> &arr){
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    FOR(i, arr.size())
        FOR(j, arr[0].size())
            ret[j][arr.size()-i-1] = arr[i][j];
//    FOR(i, ret.size()) {
//        FOR(j, ret[0].size())cout << ret[i][j];
//        cout << endl;
//    }
    return ret;
}
void printBoard(){
    FOR(i, r){
        FOR(j, c){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void printVector(const vector<pair<int, int>>& block){
    FOR(i, block.size()){
        cout << block[i].first <<" " << block[i].second << endl;
    }
}
bool set(int y, int x, const vector<pair<int, int>>& block, int val){
    bool ret = true;
    FOR(i, block.size()){
        if(0<=y+block[i].first && y+block[i].first<r && 0<=x+block[i].second && x+block[i].second<c){
            if(board[y+block[i].first][x+block[i].second]!=val) continue;
            else{
                ret = false;
                break;
            }

        }
        else{
            ret = false;
            break;
        }
    }
    if(ret){
        FOR(i, block.size()){
            board[y+block[i].first][x+block[i].second]=val;
        }
    }
    return ret;
}

void search(int placed){
    if(empty/blocksize+placed < best) return;
    int y = -1, x = -1;
    FOR(i, r){
        FOR(j, c){
            if(board[i][j] == 0){
                y = i; x = j;
                break;
            }
        }
        if(y!=-1) break;
    }

    if(y==-1){
        best = max(best, placed);
        return;
    }

    FOR(i, rotations.size()){

        if(set(y, x, rotations[i], 1)) {
            empty -= blocksize;
            search(placed+1);
            set(y, x, rotations[i], 0);
            empty += blocksize;

        }
    }
    board[y][x] = 1;
    empty--;
    search(placed);
    board[y][x] = 0;
    empty++;
}
void generateRotations(vector<string> block){ //&아니고 그냥 복사
    //roatations : block을 회전시켜 만든 4가지 블록을 pair<int, int>의 벡터로 저장
    rotations.clear();
    rotations.resize(4);
    FOR(rot, 4){
        int xindex=-1, yindex=-1;
        FOR(i, block.size()){
            FOR(j, block[0].size()){
                if(block[i][j]=='#'){
                    // 처음으로 만난 #이 블록의 가장 왼쪽 윗칸이다.
                    // 이를 (0,0)으로 해서 나머지 블록의 상대 위치를 저장한다
                    if(xindex==-1) {
                        yindex = i;
                        xindex = j;
                    }
                    rotations[rot].push_back(make_pair(i-yindex, j-xindex));
                }
            }
        }
        printVector(rotations[rot]);
        //회전
        block = rotate(block);
    }
    //중복제거
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end()); // ** unique함수 사용법 찾아보기
    blocksize = rotations[0].size();

}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
//        cout << tc << endl;
        best = 0;
        getInput();
        generateRotations(block);
//        test(0);
        search(0);
        cout << best << endl;
    }
}