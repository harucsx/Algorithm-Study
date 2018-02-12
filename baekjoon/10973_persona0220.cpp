#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

bool sorted(vector<int> &v){
	
	for(int i=0; i<v.size()-1; i++){
		if(v[i] >= v[i+1]){
			return false;
		}
	}
	return true;	
}

int main(){
	
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	vector<int> s(N);
	for(int i=0; i<N; i++){
		scanf("%d", &v[i]);
		s[i] = v[i];
	}
	
	sort(s.begin(), s.end());

	if(s==v){
		printf("-1\n");
	}
	else{
		
		prev_permutation(v.begin(), v.end() );
		
		for(int i=0; i<N; i++){
			printf("%d ", v[i]);
		}
		printf("\n");

	}
		





	return 0;
}
