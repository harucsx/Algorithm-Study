#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int check[300000];

int calc(int A, int P){

	int ret = 0;

	while(A){
		int z = 1;
		for(int i=0; i<P; i++){
			z *= A%10;
		}
		ret += z;
		A /= 10;
	}
	return ret;
}

int main(){
	
	memset(check, -1, sizeof(check));
	
	int A, P;
	scanf("%d %d", &A, &P);

	int idx = 0;
	while(1){
		check[A] = idx++;
		
		int next = calc(A, P);
		if(check[next] == -1) A = next;
		else{
			printf("%d\n", check[next]);
			break;
		}
		
	}


	return 0;
}

