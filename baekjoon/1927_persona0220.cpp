#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	
	priority_queue<int, vector<int>, greater<int> > pq;
	
	int N;
	scanf("%d", &N);

	while(N--){
		int in;
		scanf("%d", &in);
	
		if(in == 0){
			if(pq.empty()) printf("0\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}

		else{
			pq.push(in);
		}
	}
	

	return 0;
}


