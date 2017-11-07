#include <stdio.h>

int main(){
	
	int n;
	int dp[2][1001];
	int input[1001];
	int max = 0;

	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &input[i]);
	}
	
	for(int i=1; i<=n; i++){
		int max = 0;
		for(int j=0; j<i; j++){
			if(input[i] > input[j]){
				if(max < dp[0][j]) max = dp[0][j];
			}
		}
		dp[0][i] = max + 1;
	}

	for(int i=n; i>=1; i--){
		int max = 0;
		for(int j=n; j>i; j--){
			if(input[i] > input[j]){
				if(max < dp[1][j]) max = dp[1][j];
			}
		}
		if(dp[1][i] < max + 1) dp[1][i] = max + 1;
	}

	for(int i=1; i<=n; i++){
		if(max < dp[0][i] +dp[1][i]) max = dp[0][i] + dp[1][i];
	}

	printf("%d\n", max-1);
	return 0;
}

