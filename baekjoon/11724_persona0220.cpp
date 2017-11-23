#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int cnt = 0;
vector<int> adj[1001];
bool visit[1001] = {0};

void DFS(int now){
	
	visit[now] = true;
	for(int i=0; i<adj[now].size(); i++){
		if(!visit[adj[now][i]]){
			DFS(adj[now][i]);
		}	
	}
}

int main(){
	
	scanf("%d%d", &N, &M);

	int node1, node2;
	for(int i=0; i<M; i++){
		scanf("%d%d", &node1, &node2);	
	
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}

	for(int i=1; i<=N; i++){
		if(!visit[i]){
			DFS(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}

