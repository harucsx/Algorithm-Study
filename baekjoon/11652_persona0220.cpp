#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

#define ll long long

int main(){
	
	int N;
	scanf("%d", &N);

	vector<ll> v(N);

	for(int i=0; i<N; i++){
		scanf("%lld", &v[i]);
	}

	sort(v.begin(), v.end());

	int max = 1;
	ll maxk = v[0];
	int cnt = 1;
	for(int i=1; i<N; i++){
		if(v[i]== v[i-1]){
			cnt++;
		}
		else{
			cnt = 1;
		}	

		if(cnt > max){
			max = cnt;
			maxk = v[i];
		}
	}

	printf("%lld\n", maxk);

	return 0;
}

