#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int N, M;
	cin >> N >> M;

	int ans;
	if(N == 1) ans = 1;
	else if(N == 2) ans = min(4, (M+1)/2);
	else if(M <7) ans = min(4, M);
	else ans = M-2;
	
	printf("%d\n", ans);

	return 0;
}

