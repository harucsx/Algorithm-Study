#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> v(N);

	for(int i=0; i<N; i++){
		scanf("%d", &v[i]);
	}

	if(next_permutation(v.begin(), v.end())){
		for(int i=0; i<N; i++){
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
	}

	
	return 0;
}

