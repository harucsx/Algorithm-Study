#include <stdio.h>

int main(){
	
	int N, B;
	scanf("%d %d", &N, &B);

	char output[100];
	int i=0;

	while(N){
		output[i++] = N%B;
		N /= B;
	}

	for(i = i-1; i>=0; i--){
		if(0<=output[i] && output[i] <= 9){
			printf("%c", output[i] + '0');
		}
		else printf("%c", output[i]-10 +'A');
	}

	printf("\n");


	return 0;
}

