#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[100001];
int par[100001];


void DFS(int now){
	printf("now %d\n", now);	
	for(int i=0; i<adj[now].size(); i++){
		if(par[adj[now][i]] == -1){
			par[adj[now][i]] = now;
			DFS(adj[now][i]);
		}
	}

}


int main(){
	
	int N;
	scanf("%d", &N);

	int a, b;
	for(int i=0; i<N-1; i++){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(par, -1, sizeof(par));

	DFS(1);	

	for(int i=2; i<=N; i++){
		printf("%d\n", par[i]);
	}
	return 0;
}

