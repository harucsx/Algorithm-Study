#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

bool check[10000];

bool prime(int x){
	
	for(int i=2; i*i<=x; i++){
		if(x%i==0) return false;
	}

	return true;
}

int solve(int start, int end){

	queue<pair<int,int> > que;
	
	check[start] = true;
	que.push(make_pair(start, 0));

	while(!que.empty()){
		
		// cout << que.front().first << ","<< que.front().second << endl;
		pair<int,int> f = que.front();
		que.pop();

		if(f.first == end){
			return f.second;
		}
		for(int j=1; j<=1000; j*=10){

			for(int i=1; i<10; i++){


				int cand = f.first;

				cand += i*j;
				if((f.first/j)%10 + i >= 10){
					cand -= j*10;
				}

				if(cand > 1000 && prime(cand) && check[cand] == false){
					check[cand] = true;
					que.push(make_pair(cand, f.second+1));
				}
			}

		}
	}
	
	return -1;

}

int main(){
	
	int tc;
	int start, end;
	cin >> tc;
	while(tc--){
		
		for(int i=1000; i<10000; i++){
			check[i] = false;
		}

		cin >> start >> end;
		
		int answer = solve(start, end);
		if(answer == -1){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("%d\n", answer);
		}

	}

	return 0;
}

