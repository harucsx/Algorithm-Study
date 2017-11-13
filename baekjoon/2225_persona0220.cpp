#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int N, K;
	cin >> N >> K;

	int dp[201][201] = {0};

	//i 를 1개의 합으로 나타내는 경우
	for(int i=0; i<=N; i++){
		dp[1][i] = 1;
	}

	//i를 2개의 합으로 나타내는 경우
	for(int i=0; i<=N; i++){
		dp[2][i] = i+1;
	}
	
	//dp[i][j] : j를 i개의 합으로 나타내는 경우
	for(int i=3; i<=K; i++){
		for(int j=0; j<=N; j++){
			for(int k=0; k<=j; k++){
				dp[i][j] = (dp[i][j] + dp[i-1][k])%1000000000;
			}
		}
	}

	cout << dp[K][N] << endl;
	return 0;
}

