#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int adj[100001], visit[100001], cycle[100001];

int DFS(int start, int now, int depth){
	visit[now] = depth;
	cycle[now] = start;
	
	if(visit[adj[now]] == 0){
		DFS(start, adj[now], depth + 1);
	}

	else if( cycle[adj[now]] == start){
		return depth - visit[adj[now]] + 1;
	}
	else{
		return 0;
	}

}


int main(){
	
	int tc;
	scanf("%d", &tc);

	while(tc--){
		int ans = 0;

		memset(visit, 0, sizeof(visit));

		int N;
		scanf("%d", &N);

		for(int i=1; i<=N; i++){
			scanf("%d", &adj[i]);
		}
		
		for(int i=1; i<=N; i++){
			if(visit[i] == 0 && visit[adj[i]] == 0){
				ans += DFS(i, i, 1);
			}
		}
	
		printf("%d\n", N-ans);
	
	}

	return 0;
}

