#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > adj[100001];

int startNode;

int ans = 0;

void DFS(int now, int par, int dis){
	
	if(dis > ans){
		ans = dis;
		startNode = now;
	}


	for(int i=0; i<adj[now].size(); i++){
		if(adj[now][i].first != par){
			DFS(adj[now][i].first, now, dis + adj[now][i].second);
		}
	}

}


int main(){
	
	int N;
	scanf("%d", &N);

	int node1, node2, edge;
	for(int i=0; i<N; i++){
		scanf("%d", &node1);

		while(1){
			scanf("%d", &node2);
			if(node2 == -1) break;

			scanf("%d", &edge);
			adj[node1].push_back(make_pair(node2, edge));
		}
	
	}

	DFS(1, 0, 0);
	
	DFS(startNode, 0, 0);

	printf("%d", ans);

	return 0;
}

