#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	int N;
	cin >> N;

	vector<int> v(N);

	for(int i=0, a; i<N; i++){
		cin >> v[i];	
	}

	sort(v.begin(), v.end());

	int ans = 0;

	do{
		int temp = 0;
		for(int i=0; i<N-1; i++){
			temp += abs(v[i+1] - v[i]);
		}
		
		ans = max(ans, temp);
	}while(next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);
	return 0;
}

