#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int visit[20001];

bool DFS(vector<int> adj[20001], int now, int color){
	
	visit[now] = color;

	for(int i=0; i<adj[now].size(); i++){
		if(visit[adj[now][i]] == -1){
			if(!DFS(adj, adj[now][i], (color+1)%2)) return false;
		}
		else if(visit[adj[now][i]] == color){
			return false;
		}
	}
	return true;
}

int main(){
	
	int tc;
	scanf("%d", &tc);

	while(tc--){
		
		int V, E;
		scanf("%d%d", &V, &E);

		vector<int> adj[20001];	

		memset(visit, -1, sizeof(visit));
		
		int node1, node2;
		for(int i=1; i<=E; i++){
			scanf("%d%d", &node1, &node2);
			adj[node1].push_back(node2);
			adj[node2].push_back(node1);
		}
		int i;
		for(i=1; i<=V; i++){
			if(visit[i] == -1){
				if(DFS(adj, i, 0) == false){
					printf("NO\n");
					break;
				};
			}
		}
		if(i > V) printf("YES\n");
	}
	return 0;
}

