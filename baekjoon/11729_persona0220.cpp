#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int cnt = 0;

void move(int N, int start, int dest, int type){
	
	if(N == 1){
		cnt++;
		if(type == 1) printf("%d %d\n", start, dest);
		return;
	}
	else{
		if((start + dest) == 3){
			//1, 2
			move(N-1, start, 3, type);
			move(1, start, dest, type);
			move(N-1, 3, dest, type);
		}
		else if((start + dest) == 4){
			//1, 3
			move(N-1, start, 2, type);
			move(1, start, dest, type);
			move(N-1, 2, dest, type);
		}
		else if((start + dest) == 5){
			//2, 3
			move(N-1, start, 1, type);
			move(1, start, dest, type);
			move(N-1, 1, dest, type);
		}
		
	}

}

int main(){
	
	int N;
	cin >> N;

	move(N, 1, 3, 0);
	cout << cnt << endl;
	move(N, 1, 3, 1);
	
	return 0;
}  
