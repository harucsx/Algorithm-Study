#include <stdio.h>

#define ll long long

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a%b); }

int main(){
	
	int t;
	scanf("%d", &t);

	int arr[100];
	while(t--){
		int n;
		scanf("%d", &n);

		int i, j;
		for(i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}

		long long int ans = 0;
		
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				ans += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}

