#include <stdio.h>

int cacheLen[100001];
int S[100001];
int n;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int lis(int start) {
	int *ret = &cacheLen[start + 1];
	if (*ret != -1) return *ret;

	*ret = 1;
	int i;
	for (i = start + 1; i < n; i++) {
		if (start == -1 || S[start] > S[i]) {
			*ret = max(*ret, lis(i) + 1);
		}
	}
	return *ret;
}


int main() {

	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}

	for (i = 0; i < 100001; i++) {
		cacheLen[i] = -1;
	}

	printf("%d\n", lis(-1)-1);

	return 0;
}
