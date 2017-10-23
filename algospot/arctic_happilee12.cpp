//
// Created by HANLEEKYEUNG on 2017. 10. 23..
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <cstring>

#define FOR(var, ed) for(int var = 0 ; var < ed; var++)
using namespace std;

int tc, n;
vector<pair<double, double>> locations;
double dist[101][101]; // 모든 기지 사이의 거리를 미리 계산
vector<double> distSet;
void input(){
    double x, y; // 좌표를 입력받을 변수
    cin >> n;
    locations.clear();
    locations.resize(n);
    FOR(i, n){
        cin >> x >> y;
        locations[i] = make_pair(x,y);
    }
}
double calcDist(pair<double, double> point1, pair<double, double> point2){
    double ret;
    ret = sqrt(pow(point1.first-point2.first, 2)+pow(point1.second-point2.second,2));
    return ret;
}
void getDistance(){
    memset(dist, 0, sizeof(dist));
    FOR(i, n){
        FOR(j, n){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = calcDist(locations[i], locations[j]);
            distSet.push_back(dist[i][j]);
        }
    }
    sort(distSet.begin(), distSet.end());
    distSet.erase(unique(distSet.begin(), distSet.end()), distSet.end());
}
// 처음에 만든 decision함수. 한 도시에서 다른 한 도시로만 전파를 전달할 수 있다고 생각했다
bool decision2(bool visited[], int last, double distance, int numVisited){
    if(numVisited == n) return true;
    FOR(index, n){
        if(!visited[index] && dist[last][index] <= distance){
            visited[index] = true;
            if(decision2(visited, index, distance, numVisited+1)) return true;
            visited[index] = false;
        }
    }
    return false;
}
// 결정함수
bool decision(double d){
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int seen = 0;
    while(!q.empty()){
        int here = q.front(); q.pop(); ++ seen; // 이전 도시에서 닿을 수 있는 이웃 도시들을 검사해서 그 다음에 닿을 수 있는 도시들을 push
        FOR(there, n){
            if(!visited[there] && dist[here][there] <= d){
                visited[there] = true;
                q.push(there);
            }
        }
    }
    // 만약 닿을 수 없는 도시가 있었다면 n보다 seen이 작을 것
    return seen == n;
}
double optimize(){
    int low = 0, high = distSet.size();
    bool visited[101];
    while(true){
        if(low >= high-1) break;
        memset(visited, false, sizeof(visited));
        visited[0] = true;
        int mid = (low+high)/2;
        if(decision(distSet[mid])) high = mid;
//        if(decision(visited, 0, distSet[mid], 1)) high = mid;
        else low = mid;
    }
    return distSet[high];
}
int main(){
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    cout << fixed << setprecision(2);
    while(tc--){
        input();
        getDistance();
        cout << optimize() << endl;
    }
}