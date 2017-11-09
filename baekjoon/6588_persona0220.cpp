#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int check[1000001] = {1, 1};
int main(){

	for(int i=2; i<1000000; i++){
		if(check[i] == 0){
			for(int j=i*2; j<1000000; j+=i){
				check[j] = 1;
			}
		}
	}
	
	int n;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;

		for(int i=1; i<n; i++){
			if(check[i] == 0 && check[n-i] == 0){
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}
		}
	}
	
	return 0;
}

