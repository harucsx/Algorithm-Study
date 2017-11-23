#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int cnt = 0;
bool visit[1001] = {0};

void DFS(vector<int> adj[1001], int now){
	
	visit[now] = true;
	for(int i=0; i<adj[now].size(); i++){
		if(!visit[adj[now][i]]){
			DFS(adj, adj[now][i]);
		}	
	}
}

int main(){
	
	int tc;
	scanf("%d", &tc);

	while(tc--){
		
		cnt = 0;
		vector<int> adj[1001];	

		memset(visit, 0, sizeof(visit));
		
		int N;
		scanf("%d", &N);
		
		int node;
		for(int i=1; i<=N; i++){
			scanf("%d", &node);
			adj[i].push_back(node);
		}

		for(int i=1; i<=N; i++){
			if(!visit[i]){
				DFS(adj, i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

