#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int F, M, K;

	cin >> F >> M >> K ;

	int left;
	int team;
	if( F >= 2*M){
		// 여자가 남을 때
		
		team = M;
		left = F - 2*M;
		
		while(K > left){
			team--;
			K -= 3;
		}
	}
	else{
		//남자가 남을 때

		team = F/2;
		left = (F-2*team) + (M-team);

		while(K > left){
			team--;
			K -= 3;
		}
	}

	cout << team << endl;

	return 0;
}

