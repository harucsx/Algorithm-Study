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

	int a, b, c;
	for(int i=0; i<N-1; i++){
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}

	DFS(1, 0, 0);
	
	DFS(startNode, 0, 0);

	printf("%d", ans);

	return 0;
}

