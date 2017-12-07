#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int total = 0;
	
	int flag = 0;
	int now;
	while(scanf("%d", &now) != EOF){

		if(now < 0){
			flag = 1;	
		}

		if(flag == 0){
			total += now;
		}
		else{
			if(now > 0) total += now*-1;
			else total += now;
		}
	}
	
	printf("%d\n", total);

	return 0;
}

