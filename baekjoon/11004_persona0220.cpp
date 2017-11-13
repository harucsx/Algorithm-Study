#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int arr[5000001];
int main(){

	int N, K;
	cin >>N >>K;

	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+N);

	printf("%d\n", arr[K-1]);

	return 0;
}

