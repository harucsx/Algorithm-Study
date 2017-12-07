#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int N, K;
	scanf("%d%d", &N, &K);
	int arr[N];

	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}

	int ans = 0;

	while(K){
		ans += K/arr[N-1];
		K %= arr[N-1];

		N--;
	}

	printf("%d\n", ans);
	
	return 0;
}

