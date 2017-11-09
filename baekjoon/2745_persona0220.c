#include <stdio.h>
#include <string.h>

int main(){

	char input[100];
	int base;
	int k = 1;
	int ans = 0;

	scanf("%s", input);
	scanf("%d", &base);
	int len = strlen(input);


	for(int i=0; i<len; i++){
		if( '0' <= input[i] && input[i] <= '9'){
			input[i] -= '0';
		}
		else if('A' <= input[i] && input[i] <= 'Z'){
			input[i] -= 'A';
			input[i] += 10;
		}
	}


	int i;
	for(i=len-1; i>=0; i--){
		ans += input[i]*k;
		k*=base;
	}

	printf("%d\n", ans);
	return 0;
}
