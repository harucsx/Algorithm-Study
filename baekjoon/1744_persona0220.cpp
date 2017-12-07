#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int N;
	scanf("%d", &N);

	int neg[10001];
	int pos[10001];

	int idx1=0, idx2=0;

	for(int i=0; i<N; i++){
		int temp;
		scanf("%d", &temp);

		if(temp > 0) pos[idx2++] = temp;
		else neg[idx1++] = temp;
	}

	sort(neg, neg+idx1);
	sort(pos, pos+idx2, greater<int>());

	int total = 0;

	if(idx1 %2 == 1){
		neg[idx1++] = 1;
	}
	if(idx2 %2 == 1){
		pos[idx2++] = 0;
	}

	for(int i=0; i<idx1; i+=2){
		total += neg[i]*neg[i+1];
	}

	for(int i=0; i<idx2; i+=2){
		if(pos[i] + pos[i+1] < pos[i] * pos[i+1])
			total += pos[i] * pos[i+1];
		else total += pos[i] + pos[i+1];
	}

	printf("%d\n", total);
	
	

	return 0;
}

