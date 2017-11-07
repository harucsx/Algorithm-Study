#include <stdio.h>

int dp[1001][10] = {0};

int main(){

	int N;
	scanf("%d", &N);

	for(int j=0; j<10; j++){
		dp[1][j] = 1;
	}

	for(int i=2; i<=N; i++){
		for(int j=0; j<10; j++){
			for(int k=j; k<10; k++){
				dp[i][j] += dp[i-1][k] %10007;
				dp[i][j] %= 10007;
			}
		}
	}

	int ans = 0;
	for(int j=0; j<10; j++){
		ans += dp[N][j] % 10007;
	}

	printf("%d\n", ans%10007);
	
	return 0;
}
