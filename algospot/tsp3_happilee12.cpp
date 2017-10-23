//
// Created by HANLEEKYEUNG on 2017. 10. 18..
//

//https://algospot.com/judge/problem/read/TSP1
//https://algospot.com/judge/problem/read/TSP2

#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>
#include <bitset>
#define FOR(i, ed) for(int i = 0 ; i < ed; i++)
#define INF numeric_limits<double>::infinity();
#define MAX 30
using namespace std;

// input
int tc, n;
// for algorithm
double best;
double dist[MAX][MAX]; //distances between city i and j
double minEdge[MAX];
vector<int> nearest[MAX];
//상호 배타적 집합 자료구조
struct DisjointSet{
    DisjointSet(int n);
    int find(int here);
    bool merge(int a, int b);//a가 포함된 집합과 b가 포함된 집합을 합침
};
//모든 도시 간 도로의 길이를 정렬
vector<pair<double, pair<int, int>>> edges;
//MST
double mstHeuristic(int here, const vector<bool>&visited){
    DisjointSet sets(n);
    double taken = 0;
    FOR(i, edges.size()){
        int a = edges[i].second.first, b=edges[i].second.second;
        if(a!=0 && a!= here && visited[a]) continue;
        if(b!=0 && b!= here && visited[b]) continue;
        if(sets.merge(a, b))
            taken += edges[i].first;
    }
    return taken;
}
double solve4(){
    edges.clear();
    FOR(i, n){
        FOR(j, n){
            edges.push_back(make_pair(dist[i][j], make_pair(i, j)));
        }
        sort(edges.begin(), edges.end());
    }

}
void inputData(){
    FOR(i, n)
        FOR(j, n)
            cin >> dist[i][j];
}

//path의 마지막 4개 도시 중 가운데 두개 도시 순서를 바꿨을 때 더 짧아지는지 여부
bool pathSwapPruning(const vector<int>& path){
    if(path.size()<4) return false;
    int p = path[path.size()-4];
    int a = path[path.size()-3];
    int b = path[path.size()-2];
    int q = path[path.size()-1];
    return dist[p][a]+dist[b][q] > dist[p][b]+dist[a][q];
}
//시작 도시와 현재 도시를 제외한 모든 path의 부분경로를 뒤집어본다
bool pathReversePruning(const vector<int>& path){
    if(path.size()<4) return false;
    int b = path[path.size()-2];
    int q = path[path.size()-1];
    FOR(i, path.size()-3){
        int p = path[i];
        int a = path[i+1];
        // [...p a ... b q...] 를 [...p b ... a q ...]로 바꿔본다
        if(dist[p][a] + dist[b][q] > dist[p][b]+dist[a][q])
            return true;
    }
    return false;

}
double simpleHeuristics(vector<bool>& visited){
    double ret = 0;
    FOR(i, n){
        if(!visited[i])
            ret+=minEdge[i];
    }
    return ret;
}
//path reverse pruning
void search4(vector<int>&path, vector<bool>& visited, double currentLength){
    if(pathReversePruning(path)) return;
    int here = path.back();
    if(path.size()==n){
        best = min(best, currentLength);
        return;
    }
    FOR(i, nearest[here].size()){
        int next = nearest[here][i];
        if(visited[next]) continue;
        path.push_back(next);
        visited[next] = true;
        search4(path, visited, currentLength+dist[here][next]);
        visited[next] = false;
        path.pop_back();
    }
}
// nearest cities
void search3(vector<int>&path, vector<bool>& visited, double currentLength){
    if(best <= currentLength+simpleHeuristics(visited)) return;
    int here = path.back();
    if(path.size()==n){
        best = min(best, currentLength);
        return;
    }
    FOR(i, nearest[here].size()){
        int next = nearest[here][i];
        if(visited[next]) continue;
        path.push_back(next);
        visited[next] = true;
        search3(path, visited, currentLength+dist[here][next]);
        visited[next] = false;
        path.pop_back();
    }
}
// simple heuristics
void search2(vector<int>&path, vector<bool>& visited, double currentLength){
    if(best <= currentLength+simpleHeuristics(visited)) return;
    int here = path.back();
    if(path.size()==n){
        best = min(best, currentLength);
        return;
    }
    FOR(next, n){
        if(visited[next]) continue;
        path.push_back(next);
        visited[next] = true;
        search2(path, visited, currentLength+dist[here][next]);
        visited[next] = false;
        path.pop_back();
    }
}

void search(vector<int>&path, vector<bool>& visited, double currentLength){
    if(best <= currentLength) return;
    int here = path.back();
    if(path.size()==n){
        best = min(best, currentLength);
        return;
    }
    FOR(next, n){
        if(visited[next]) continue;
        path.push_back(next);
        visited[next] = true;
        search(path, visited, currentLength+dist[here][next]);
        visited[next] = false;
        path.pop_back();
    }
}
double solve3(int start){
    //nearest init
    FOR(i, n){
        vector<pair<int, int>> order;
        FOR(j, n){
            if(i!=j)
                order.push_back(make_pair(dist[i][j], j));
        }
        sort(order.begin(), order.end());
        nearest[i].clear();
        FOR(j, n-1){
            nearest[i].push_back(order[j].second);
        }
    }
    FOR(i, n){
        minEdge[i] = INF;
        FOR(j, n){
            if(i!=j) minEdge[i] = min(minEdge[i], dist[i][j]);
        }
    }
    best = INF;
    vector<bool> visited(n, false);
    vector<int> path(1, start);
    visited[start] = true;
    search(path, visited, 0);
    return best;
}
double solve2(int start){
    FOR(i, n){
        minEdge[i] = INF;
        FOR(j, n){
            if(i!=j) minEdge[i] = min(minEdge[i], dist[i][j]);
        }
    }
    best = INF;
    vector<bool> visited(n, false);
    vector<int> path(1, start);
    visited[start] = true;
    search(path, visited, 0);
    return best;
}

double solve(int start){
    best = INF;
    vector<bool> visited(n, false);
    vector<int> path(1, start);
    visited[start] = true;
    search(path, visited, 0);
    return best;
}

int main(){
    clock_t begin, end;
    begin = clock();
//    freopen("input.txt", "r", stdin);
    cin >> tc;
    while(tc--){
        cin >> n;
        inputData();
        double rslt = INF;
        FOR(start, n){
            rslt = min(rslt, solve3(start));
        }
        cout.precision(10);
        cout << rslt << endl;
    }
//    printf("[Process finished in %15.10f.]\n", (double)(clock() - begin) / CLOCKS_PER_SEC);

}
