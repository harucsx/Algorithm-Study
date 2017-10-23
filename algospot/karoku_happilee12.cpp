#include<cassert>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int INF = 987654321;
const int WHITE = 1;
const int BLACK = 0;

int maskSum[1024], maskLen[1024];
int candidates[10][46][1024]; // candidates[len][sum][known] : len 칸의 합이 sum 이고, 이 칸들에 이미 쓰인 수의 집합이 known 일 때 나머지 칸에 들어갈 수 있는 숫자의 집합
const int MAXN = 55;

// color : 처음 인풋 (0 = 검은 칸 혹은 힌트 칸, 1 = 흰 칸)
// value: 반환할 보드. 빈칸이 숫자로 채워져 있다
// hint: 각 칸에 해당하는 가로(0), 세로(1) 힌트.
int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
int q, sum[MAXN*MAXN], length[MAXN*MAXN], known[MAXN*MAXN];

void calcMasks() {
    memset(maskSum, 0, sizeof(maskSum));
    memset(maskLen, 0, sizeof(maskLen));
    for(int mask = 0; mask < 1024; mask++) {
        for(int i = 0; i < 10; i++)
            if(mask & (1<<i)) {
                maskSum[mask] += i;
                maskLen[mask]++;
            }
    }
}

// mask 에 속한 원소들의 개수를 반환한다
int setSize(int mask) { return maskLen[mask]; }
// mask 에 속한 원소들의 합을 반환한다
int setSum(int mask) { return maskSum[mask]; }

// candidates[len][sum][known] : len 칸의 합이 sum 이고, 이 칸들에 이미 쓰인 수의 집합이 known 일 때 나머지 칸에 들어갈 수 있는 숫자의 집합
void generateCandidates() {
    // 우선 전부 0 으로 초기화
    memset(candidates, 0, sizeof(candidates));
    // 1~9 의 부분집합을 전부 생성한다
    for(int set = 0; set < 1024; set += 2) { // 칸에 0을 쓸 수는 없으므로 2^0씩이 아닌 2^1씩 더해야 함
        // 집합의 크기와 원소의 합을 계산해 둔다
        int l = setSize(set), s = setSum(set);
        // set 의 모든 부분집합에 대해 candidates[][][] 를 업데이트한다
        int subset = set;
        while(true) {
            // 숫자 l 개의 합이 s 이고, 이미 subset 숫자가 쓰여 있을 때
            // 전체 숫자의 집합이 set 이 되도록 나머지 숫자를 채워넣을 수 있다
            // set & ~subset : set에 있으면서 subset에는 없는 숫자 집합
            candidates[l][s][subset] |= (set & ~subset); // ****왜 =는 안되고 |=는 되지
            if(subset == 0) break;
            subset = (subset - 1) & set;
        }
    }
}
//void printCandidates(){
//    for(int set = 0; set < 1024; set += 2) {
//        cout << "---------set : " << bitset<10>(set) << "-------------" << endl;
//        int l = setSize(set), s = setSum(set);
//        int subset = set;
//        while(true) {
//            cout << "candidates["<<l<<"]["<<s<<"]["<<bitset<10>(subset)<<"] : " << bitset<10>(candidates[l][s][subset]) << endl;
//            if(subset == 0) break;
//            subset = (subset - 1) & set;
//        }
//    }
//    cout << "print end" << endl;
//}


// (y,x) 에 val 을 쓴다
// hint[y][x][h] : [y][x]칸의 가로와 세로 힌트 번호
// known[힌트번호] : 해당 힌트 번호 관련 칸들중 이미 쓴 번호
void put(int y, int x, int val) {
    for(int h = 0; h < 2; h++)
        known[hint[y][x][h]] += (1<<val);
    value[y][x] = val;
}

// (y,x) 에 쓴 val 을 지운다
void remove(int y, int x, int val) {
    for(int h = 0; h < 2; h++)
        known[hint[y][x][h]] -= (1<<val);
    value[y][x] = 0;
}

// 힌트 인덱스가 주어질 때 후보의 집합을 반환한다
// 힌트 인덱스를 바탕으로 length[hint], sum[hint], known[hint]를 찾은다음
// 미리 계산해둔 candidates에서, 해당 조건에서의 후보의 집합을 찾아 반환한다
int getCandHint(int hint) {
    return candidates[length[hint]][sum[hint]][known[hint]];
}
// 좌표가 주어질 때 해당 칸에 들어갈 수 있는 후보의 집합을 반환한다
int getCandCoord(int y, int x) {
    // hint[y][x][0] : [y][x]를 포함한 가로힌트의 인덱스 반환
    // hint[y][x][1] : [y][x]를 포함한 세로힌트의 인덱스 반환
    // 가로&세로 힌트가 반환한 빈칸에 넣어도 되는 숫자 집합들의 교집합
    // ** 교집합을 비트마스크로 쉽게 표현 가능
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

void printSolution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%s%d", (j ? " " : ""), value[i][j]);
        printf("\n");
    }
}

bool search() {
    // 들어갈 수 있는 수의 종류가 최소인 칸을 찾아보자
    int y = -1, x = -1, minCands = 1023;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(color[i][j] == WHITE && value[i][j] == 0) { // 채워야하는 칸을 아직 채우지 않았을 때
                int cands = getCandCoord(i, j);
                if(setSize(minCands) > setSize(cands)) { // 들어갈 수 있는 후보 숫자 집합의 크기를 비교
                    minCands = cands;
                    y = i; x = j;
                }
            }

    // 이 칸에 들어갈 숫자가 없으면 실패! minCands == 0000000 이라는 건 아무 숫자도 못넣는다는 뜻
    if(minCands == 0) return false;

    // 모든 칸이 채워졌으면 출력하고 종료한다
    if(y == -1) {
        printSolution();
        return true;
    }

    // 숫자를 하나씩 채워보자
    for(int val = 1; val <= 9; ++val)
        if(minCands & (1<<val)) { // minCands 의 val 비트가 켜져있다 <=> 숫자 val을 채울 수 있다
            put(y, x, val);
            if(search()) return true;
            remove(y, x, val);
        }

    return false;
}

void read() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> color[i][j];

    memset(hint, -1, sizeof(hint));

    cin >> q;
    int dy[2] = { 0, 1 };
    int dx[2] = { 1, 0 };
    for(int i = 0; i < q; i++) {
        int y, x, direction;
        cin >> y >> x >> direction >> sum[i]; // sum[i] i번째 힌트의 값. (해당 방향으로 빈칸을 합쳤을 때 나와야 하는 값)
        --y; --x;
        length[i] = 0;
        while(true) {
            y += dy[direction]; x += dx[direction];
            if(y >= n || x >= n || color[y][x] == BLACK) break; //board 범위를 넘어가거나 검은 칸을 만나면 break;
            hint[y][x][direction] = i; //아니면 hint에 해당 힌트의 인덱스를 저장
            length[i]++; //length[i] : i번째 힌트가 cover중인 칸의 수
        }
    }
    memset(known, 0, sizeof(known));
}

int main() {
    freopen("input.txt","r",stdin);
    calcMasks();
    generateCandidates();
//    printCandidates();

    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
        read();
        memset(value, 0, sizeof(value));
        assert(search());
    }
}