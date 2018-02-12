#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int parent[1000001];

int Find(int x){
	if(parent[x] == x){
		return x;
	}

	else{
		return parent[x] = Find(parent[x]);
	}
}

void Union(int a, int b){
	
	a = Find(a);
	b = Find(b);

	if(a != b){
		parent[b] = a;
	}

}

int main(){
	
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		parent[i] = i;
	}

	for(int i=0; i<m; i++){
		int comm, a, b;
		scanf("%d%d%d", &comm, &a, &b);
		
		if(comm == 0){
			Union(a, b);
		}
		else if(comm == 1){
			if(Find(a) == Find(b)){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}

	return 0;
}

